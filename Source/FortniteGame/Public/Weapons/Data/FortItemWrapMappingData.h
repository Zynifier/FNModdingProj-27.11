// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Items/FortItemTypeEnum.h"
#include "FortItemWrapMappingData.generated.h"

class UAnimInstance;
class UMaterialInterface;
class UObject;
class UTexture2D;

USTRUCT(BlueprintType)
struct FItemWrapPreviewEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemWrapPreviewEntry", meta=(AllowedClasses="/Script/Engine.SkeletalMesh,/Script/FortniteGame.FortWeaponItemDefinition"))
	TSoftObjectPtr<UObject> PreviewObject;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemWrapPreviewEntry", meta=(AllowedClasses="/Script/Engine.AnimationAsset"))
	TSoftObjectPtr<UObject> PreviewObjectAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemWrapPreviewEntry")
	TSoftClassPtr<UAnimInstance> PreviewObjectAnimInstance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemWrapPreviewEntry")
	FTransform PreviewTransform;

	UPROPERTY(EditAnywhere, Category="ItemWrapPreviewEntry", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EItemWrapSectionNames"))
	int32 WrapSectionMask;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemWrapPreviewEntry")
	uint8 bPreviewUsingVehicleShader : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemWrapPreviewEntry", meta=(AllowedClasses="/Script/Engine.AnimationAsset"))
	TSoftObjectPtr<UObject> PreviewObjectFiringAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemWrapPreviewEntry", meta=(AllowedClasses="/Script/Engine.ParticleSystem"))
	TSoftObjectPtr<UObject> PreviewObjectMuzzleFlashParticleSystem;

};

USTRUCT(BlueprintType)
struct FItemWrapSlotMetadata
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="ItemWrapSlotMetadata")
	FString SlotDescription;
#endif

	UPROPERTY(EditAnywhere, Category="ItemWrapSlotMetadata")
	FGameplayTagQuery MatchCriteria;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemWrapSlotMetadata")
	TArray<FItemWrapPreviewEntry> PreviewList;

	UPROPERTY(EditAnywhere, Category="ItemWrapSlotMetadata")
	EFortItemType PreviewListItemDefinitionType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemWrapSlotMetadata")
	TSoftObjectPtr<UTexture2D> SlotImage;

	UPROPERTY(EditAnywhere, Category="ItemWrapSlotMetadata")
	int32 PreviewListSortOrder;

};

UCLASS(BlueprintType)
class UFortItemWrapMappingData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortItemWrapMappingData")
	TSoftObjectPtr<UMaterialInterface> MasterVehicleMaterial;

	UPROPERTY(EditAnywhere, Category="FortItemWrapMappingData")
	TSoftObjectPtr<UMaterialInterface> MasterWeaponMaterial;

	UPROPERTY(EditAnywhere, Category="FortItemWrapMappingData")
	TSoftObjectPtr<UMaterialInterface> MasterCharacterMaterial;

	UPROPERTY(EditAnywhere, Category="FortItemWrapMappingData")
	FGameplayTag DoNotApplyWrapsTag;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemWrapMappingData", meta=(TitleProperty="SlotDescription"))
	TArray<FItemWrapSlotMetadata> SlotMetadata;

};

