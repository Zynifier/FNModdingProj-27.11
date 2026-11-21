// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortCustomPartTypeEnum.h"
#include "FortCharmsMappingData.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FCharmPreviewEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CharmPreviewEntry", meta=(AllowedClasses="/Script/Engine.SkeletalMesh,/Script/FortniteGame.FortWeaponItemDefinition"))
	TSoftObjectPtr<UObject> PreviewObject;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CharmPreviewEntry")
	FTransform PreviewTransform;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CharmPreviewEntry")
	uint8 bPreviewUsingVehicleShader : 1;

};

USTRUCT(BlueprintType)
struct FCharmSlotMetadata
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="CharmSlotMetadata")
	FString SlotDescription;
#endif

	UPROPERTY(EditAnywhere, Category="CharmSlotMetadata")
	TEnumAsByte<EFortCustomPartType::Type> AttachToPart;

	UPROPERTY(EditAnywhere, Category="CharmSlotMetadata")
	bool WeaponCharm;

	UPROPERTY(EditAnywhere, Category="CharmSlotMetadata")
	bool BackPresentedCharm;

	UPROPERTY(EditAnywhere, Category="CharmSlotMetadata")
	FName AttachSocket;

	UPROPERTY(EditAnywhere, Category="CharmSlotMetadata")
	FGameplayTagQuery MatchCriteria;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CharmSlotMetadata")
	TArray<FCharmPreviewEntry> PreviewList;

};

UCLASS(BlueprintType)
class UFortCharmsMappingData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCharmsMappingData", meta=(TitleProperty="SlotDescription"))
	TArray<FCharmSlotMetadata> SlotMetadata;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCharmsMappingData")
	TArray<FCharmPreviewEntry> NonSlotPreviewList;

	UPROPERTY(EditAnywhere, Category="FortCharmsMappingData")
	FGameplayTag DoNotApplyCharmsTag;

};

