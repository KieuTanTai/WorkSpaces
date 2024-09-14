void Sort_Array(int **array, int row, int column)
{
     std::ofstream sort_file;
     sort_file.open("../../Documents/sort_file.txt");
     if(!sort_file.is_open())
          return;
     sort_file<<row<<"\t"<<column<<std::endl;
     //sort array
     for(int j=0; j<column; j++)
     {
          int *temp = new int[row];
          for(int i=0; i<row; i++)
               temp[i] = array[j][i];
          std::sort(temp, temp+row);
          for(int i=0; i<row; i++)
               array[j][i] = temp[i];
          delete []temp;
     }
     for(int j=0; j<column; j++)
     {
          for(int i=0; i<row; i++)
               sort_file<<array[j][i]<<"\t";
          sort_file<<std::endl;
     }
     sort_file.close();
}