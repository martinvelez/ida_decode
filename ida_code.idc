// This script starts at the beginning of the binary file and starts converting the binary into assembly code.  It can handle binary code with multiple instructions.  It can even handle code which does not decode into whole assembly instructions.
static main(void){
    auto entry, end, asmsize, bytes, fp, res, ifname, fptwo, fptwolen;
    bytes = -1;
    entry = 0;
    end = 0;
    while(bytes != 0){
        bytes = MakeCode(end);
        end = end + bytes;
    }
    asmsize = end - entry;
    ifname = GetInputFilePath();
    fptwo = fopen(ifname, "r");
    fptwolen = filelength(fptwo);
    fclose(fptwo);
    if(asmsize != fptwolen){
        Exit(1);
    }
    fp = fopen("temp.asm", "w");
    res = GenerateFile(4, fp, entry, end, 0);
    fclose(fp);
    Exit(0);
}
