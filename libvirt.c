/* program to implement basic operations for XEN virtual machine using libvirt API*/

#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>

int main(int argc, char *argv[])
{
    virConnectPtr contn;
    virDomainPtr vdptr;
    int index=-1,choice; 	
    char *host;
    contn = virConnectOpen("xen:///");
    if (contn == NULL) {
        fprintf(stderr, "Failed to connect to xen:///\n");
        return 1;
    }
    //host = virConnectGetHostname(conn);

    vdptr=virDomainLookupByName(contn,"ubuntu_new");
    printf("\n 1.Start \n 2.Suspend\n 3.Resume \n 4.Shutdown\n");

    printf("Enter your choice:\n");
    scanf("%d",&choice);

    switch(choice) {

        case 1:
 		/*Start*/
            index=virDomainCreate(vdptr);
            if(index==0)
            {
                printf("Success\n");
            }else{
                printf("Failed \n");
            }
            break;


        case 2:

            /* suspend*/	    
            index=virDomainSuspend(vdptr);
            if(index==0)
            {
                printf("Success\n");
            }else{
                printf("Failed\n");	
            }
            break;


        case 3:

            /*resume*/
            index=virDomainResume(vdptr);
            if(index==0)
            {	
                printf("Success\n");
            }else{
                printf("Failed\n");	
            }
            break;

        case 4:
           
            /*shutdown*/
            index=virDomainDestroy(vdptr);
            if(index==0)
            {
                printf("Success\n");
            }else{
                printf("Failed\n");	
            }
            break;        

         default:
        
            printf("Invalid Choice");


            virConnectClose(contn);
            return 0;
    }
}
