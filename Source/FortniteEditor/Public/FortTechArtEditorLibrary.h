// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortTechArtEditorLibrary.generated.h"

class USkeletalMeshComponent;

UCLASS()
class UTechArtEditorHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	UFUNCTION(BlueprintCallable)
	static bool QuerryIfSkeletonTexturesAreAtHighestQuality(USkeletalMeshComponent* SkeletalMeshPart);
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable)
	static void TagSkeletonTexturesForHighestQuality(USkeletalMeshComponent* SkeletalMeshPart);
#endif

};

