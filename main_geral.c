
#include "funcoes_auxiliares.h"

int main(int argc, char *argv[])
   {
   int ii;
   Cube *cubo;
   FILE *fp;
   struct params_list lista_parametros;
   int VAR[4] = {DZ_INDEX, CZ_INDEX, VR_INDEX, SW_INDEX};
   int var_idx, i;
   
   if (argc != 2)
      {
      printf("Uso: %s <arquivo>\n", argv[0]);
      return -1;
      }
   
   memset(&lista_parametros, 0, sizeof(struct params_list));

   strcpy(lista_parametros.file_list[0], argv[1]);
   lista_parametros.nx = 500;
   lista_parametros.ny = 500;
   lista_parametros.nz = 18;
   lista_parametros.dx = 1000;
   lista_parametros.dy = 1000;
   lista_parametros.dz = 1000;
   lista_parametros.radar_x = 250;
   lista_parametros.radar_y = 250;
   lista_parametros.radar_z = 0;
   lista_parametros.nvars = 1;
   lista_parametros.nlevels = 15;
   lista_parametros.vars[0] = CZ_INDEX;
   for (i = 0; i < lista_parametros.nlevels; i++)
      lista_parametros.levels[i] = (i + 2)*1000;
   
   strcpy(lista_parametros.sufixo, "cappi");
   lista_parametros.produto = PROD_CAPPI;
   (void) faz_cappi(&lista_parametros);
   
   lista_parametros.nlevels = 3;
   lista_parametros.levels[0] = 20;
   lista_parametros.levels[1] = 35;
   lista_parametros.levels[2] = 45;
   strcpy(lista_parametros.sufixo, "echotop");
   lista_parametros.produto = PROD_TOP;
   (void) faz_echotop(&lista_parametros);
   
   /*faz VIL entre 1000 e 16000 m*/
   lista_parametros.nlevels = 2;
   lista_parametros.levels[0] = 2000;
   lista_parametros.levels[1] = 16000;
   strcpy(lista_parametros.sufixo, "vil");
   (void) faz_vil(&lista_parametros);
      
   
   lista_parametros.nx = 666;
   lista_parametros.ny = 666;
   lista_parametros.nz = 1;
   lista_parametros.dx = 750;
   lista_parametros.dy = 750;
   lista_parametros.dz = 1000;
   lista_parametros.radar_x = 333;
   lista_parametros.radar_y = 333;
   lista_parametros.radar_z = 0;
   lista_parametros.nvars = 2;
   lista_parametros.vars[0] = CZ_INDEX;
   lista_parametros.vars[1] = VR_INDEX;

   lista_parametros.nlevels = 15;
   for (i = 0; i < lista_parametros.nlevels; i++)
      lista_parametros.levels[i] = i + 1;
   
   lista_parametros.produto = PROD_PPI;
   strcpy(lista_parametros.sufixo, "ppi");
   (void) faz_ppi(&lista_parametros);
   
   return 0;
   }
