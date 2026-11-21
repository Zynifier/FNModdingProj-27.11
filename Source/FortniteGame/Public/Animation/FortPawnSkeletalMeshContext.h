// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortPawnSkeletalMeshContext.generated.h"

class AFortPlayerPawn;
class UAnimInstance;
class UMaterialInterface;
class USkeletalMesh;

USTRUCT()
struct FFortPawnSkeltalMeshSettings
{
	GENERATED_BODY()

public:
	UPROPERTY()
	USkeletalMesh* SkeletalMesh;

	UPROPERTY()
	TSubclassOf<UAnimInstance> AnimInstanceClass;

	UPROPERTY()
	TArray<UMaterialInterface*> MeshMaterials;

	UPROPERTY()
	bool bShouldHideCharacterParts;

};

UCLASS(MinimalAPI)
class UFortPawnSkeletalMeshContext : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	AFortPlayerPawn* FortPlayerPawn;

	UPROPERTY(Transient)
	FFortPawnSkeltalMeshSettings RestorationSettings;

};

