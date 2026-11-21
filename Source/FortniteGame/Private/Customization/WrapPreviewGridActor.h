// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Math/MathFwd.h"
#include "UObject/SoftObjectPath.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "WrapPreviewGridActor.generated.h"

class AActor;
class UAthenaItemWrapDefinition;
class USkeletalMesh;
class UTexture2D;

UENUM()
enum class EWrapPreviewGridLockerMode : uint8
{
	// Show all weapons that pass the other filters, whether or not they have a home in the locker

	IgnoreLockerConfiguration = 0,
	// Show weapons that have a home in the locker (and therefore will be shown in game)

	SupportedWeaponsOnly = 1,
	// Hide weapons that have a home in the locker (and therefore will be shown in game), showing a list of weapons that aren't wrap-ready yet

	UnsupportedWeaponsOnly = 2,
};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AWrapPreviewGridActor : public AInfo
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWrap(UAthenaItemWrapDefinition* NewWrap);

protected:
	UPROPERTY(EditAnywhere, Category="Config")
	bool bScanForWeapons;

	UPROPERTY(EditAnywhere, Category="Config")
	bool bShowRangedWeapons;

	UPROPERTY(EditAnywhere, Category="Config")
	bool bShowMeleeWeapons;

	UPROPERTY(EditAnywhere, Category="Config", meta=(DisplayName="Exclude Prototype Weapons"))
	bool bExcludePrototypeRangedWeapons;

	UPROPERTY(EditAnywhere, Category="Config", meta=(DisplayName="Filter Out Rarity Dupes For Weapons"))
	bool bFilterOutRarityDupesForRangedWeapons;

	UPROPERTY(EditAnywhere, Category="Config")
	bool bFilterOutTierDupesForWeapons;

	UPROPERTY(EditAnywhere, Category="Config")
	bool bFilterOutCraftingMaterialDupesForWeapons;

	UPROPERTY(EditAnywhere, Category="Config")
	EWrapPreviewGridLockerMode LockerFilterMode;

	UPROPERTY(EditAnywhere, Category="Config")
	bool bShowOnlyItemsThatDontHaveWrapLockerSlot;

	UPROPERTY(EditAnywhere, Category="Config")
	bool bShowWrapMatchIcon;

	UPROPERTY()
	bool bHasSectionLimit;

	UPROPERTY(EditAnywhere, Category="Config", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EItemWrapSectionNames", EditCondition="bHasSectionLimit"))
	int32 MaterialSectionMask;

	UPROPERTY(EditAnywhere, Category="Config", meta=(GetOptions="GetMeshComponentNames"))
	TArray<FName> ComponentNameAllowList;

	UPROPERTY(EditAnywhere, Category="Config", meta=(ContentDir))
	FDirectoryPath RangedWeaponPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config")
	TArray<TSubclassOf<AActor>> ListOfActorsToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config")
	TArray<TObjectPtr<USkeletalMesh>> ListOfMeshesToSpawn;

	UPROPERTY(BlueprintReadOnly, Category="WrapPreviewGridActor")
	TArray<TObjectPtr<AActor>> SpawnedActors;

	UPROPERTY(EditAnywhere, Category="Visuals", meta=(EditCondition="bShowWrapMatchIcon"))
	TArray<TObjectPtr<UTexture2D>> LockerCategoryMarkers;

	UPROPERTY(EditAnywhere, Category="Visuals", meta=(EditCondition="bShowWrapMatchIcon"))
	TObjectPtr<UTexture2D> FailedToMatchLockerMarker;

	UPROPERTY(EditAnywhere, Category="Visuals", meta=(EditCondition="bShowWrapMatchIcon"))
	float StatusIconSize;

	UPROPERTY(EditAnywhere, Category="Visuals", meta=(EditCondition="bShowWrapMatchIcon"))
	bool bStatusIconScreenSizeScaled;

	UPROPERTY(EditAnywhere, Category="Visuals")
	TArray<FMcpVariantChannelInfo> VariantData;

private:
	UFUNCTION(meta=(CallInEditor="true"))
	static TArray<FName> GetMeshComponentNames();

	UPROPERTY(EditAnywhere, Category="Config")
	TObjectPtr<UAthenaItemWrapDefinition> WrapToApply;

	UPROPERTY(EditAnywhere, Category="Config")
	EItemWrapMaterialType MaterialTypeForRawMeshes;

	UPROPERTY(EditAnywhere, Category="ViewConfig")
	FVector SpawnAxisX;

	UPROPERTY(EditAnywhere, Category="ViewConfig")
	FVector SpawnAxisY;

	UPROPERTY(EditAnywhere, Category="ViewConfig")
	int32 WidthInItems;

	UPROPERTY(EditAnywhere, Category="ViewConfig")
	FVector2D SpawnSpacing;

	UPROPERTY(EditAnywhere, Category="ViewConfig")
	FRotator SpawnRotation;

	UPROPERTY(EditAnywhere, Category="ViewConfig")
	FVector IconOffset;

};

