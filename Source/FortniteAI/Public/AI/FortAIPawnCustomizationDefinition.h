// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Athena/AthenaMemoryBudgetInterface.h"
#include "FortReleaseVersion.h"
#include "FortAIPawnCustomizationDefinition.generated.h"

class AActor;
class UAnimInstance;
class UCustomCharacterPart;
class UMaterialInterface;
class USkeletalMesh;

USTRUCT()
struct FFortAIPawnMaterialDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAIPawnMaterialDefinition")
	TSoftObjectPtr<UMaterialInterface> Material;

	UPROPERTY(EditAnywhere, Category="FortAIPawnMaterialDefinition")
	bool bRequireDynamicInstance;

};

UCLASS(MinimalAPI)
class UFortAIPawnCustomizationDefinition : public UPrimaryDataAsset, public IAthenaMemoryBudgetInterface
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, DuplicateTransient, Category="ReleaseVersion")
	FFortReleaseVersion FortReleaseVersion;
#endif

	UPROPERTY(EditAnywhere, Category="Mesh")
	TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(EditAnywhere, Category="FortAIPawnCustomizationDefinition")
	TSoftClassPtr<AActor> CharacterBlueprint;

	UPROPERTY(EditAnywhere, Category="Materials")
	TArray<FFortAIPawnMaterialDefinition> OverrideMaterials;

	UPROPERTY(EditAnywhere, Category="Animation")
	TSoftClassPtr<UAnimInstance> AnimationBP;

	UPROPERTY(EditAnywhere, Category="FortAIPawnCustomizationDefinition")
	TArray<TObjectPtr<UCustomCharacterPart>> CharacterParts;

};

