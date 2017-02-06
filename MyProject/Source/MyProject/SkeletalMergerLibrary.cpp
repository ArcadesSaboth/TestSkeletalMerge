// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "Runtime/Engine/Public/SkeletalMeshMerge.h"
#include "Runtime/Engine/Classes/Animation/Skeleton.h"
#include "SkeletalMergerLibrary.h"

DEFINE_LOG_CATEGORY(skeletalMeshLibrary)

USkeletalMesh* USkeletalMergerLirary::MergeSkeleton(UObject* parentOwner, const TArray<USkeletalMesh*>& InMergeList)
{
	if (InMergeList.Num() == 0)
		return nullptr;

	// Only for debug purpose. RefSkeleton should be sorted to have a proper printing but it works anyway.
	/*for (int i = 0; i < InMergeList.Num(); ++i)
	{
	FString skeleton(PrintSkeletalTree(InMergeList[i]->RefSkeleton));
	UE_LOG(skeletalMeshLibrary, Warning, TEXT("Skeleton %d: %s\n"), i, *skeleton);
	}*/

	FName tempName("MergeSkeletalMesh");
	USkeletalMesh* OutMesh = NewObject<USkeletalMesh>(parentOwner, tempName, EObjectFlags::RF_NoFlags, InMergeList[0], true);

	TArray<FSkelMeshMergeSectionMapping> unused;
	FSkeletalMeshMerge merger(OutMesh, InMergeList, unused, 0);
	merger.SetGeometryReskinning(true);
	merger.DoMerge();

	// As well..
	/*FString tolog(PrintSkeletalTree(OutMesh->RefSkeleton));
	UE_LOG(skeletalMeshLibrary, Warning, TEXT("Resulting skeleton: %s"), *tolog);*/

	return OutMesh;
}

