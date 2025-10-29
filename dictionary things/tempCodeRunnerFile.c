/ Search test
    color found = search(a, "Green");
    if(found.RGBval[0] != -1)
        printf("\nFound color: %s (%d, %d, %d)\n", 
               found.colorName, 
               found.RGBval[0], found.RGBval[1], found.RGBval[2]);

    // Delete test
    delete(a, "Blue");
    printf("\n--- Display after deleting Blue ---\n");
    display(a);

    return 0;