// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "SkeletalMergerLibrary.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(skeletalMeshLibrary, All, All);

/**
 * 
 */
UCLASS()
class MYPROJECT_API USkeletalMergerLirary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Utilities|Graphic", Meta = (DisplayName = "Skeletal Merger"))
	static USkeletalMesh* MergeSkeleton(UObject* parentOwner, const TArray<USkeletalMesh*>& InMergeList);
	
};
