// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Animation/FortEmoteMapping.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "FortCustomBodyTypeEnum.h"
#include "FortGender.h"
#include "FortMontageItemDefinitionBase.generated.h"

class AFortPawn;
class AFortPlayerController;
class AFortPlayerPawn;
class UAnimMontage;
class UAthenaCosmeticItemDefinition;
class UFortItemAccessTokenType;
class UFortItemDefinition;

UENUM()
enum class EMontageVisibilityRule : uint8
{
	/** In order for the montage to be visible, this item must be equipped */
	RequiredItem = 0,
	/** In order for the montage to be visible, this item must NOT be equipped */
	ForbiddenItem = 1,
	/** In order for the montage to be visible, the player's loadout meta-tags must meet this gameplay tag query */
	MetaTagQuery = 2,
};

USTRUCT()
struct FMontageItemAccessData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MontageItemAccessData")
	FGameplayTag AccessTag;

	UPROPERTY(EditAnywhere, Category="MontageItemAccessData")
	TObjectPtr<UFortItemAccessTokenType> AccessToken;

};

USTRUCT()
struct FMontageVisibilityData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MontageVisibilityData")
	EMontageVisibilityRule Rule;

	UPROPERTY(EditAnywhere, Category="MontageVisibilityData", meta=(EditCondition="Rule == EMontageVisibilityRule::RequiredItem || Rule == EMontageVisibilityRule::ForbiddenItem", EditConditionHides))
	TObjectPtr<UFortItemDefinition> Item;

	UPROPERTY(EditAnywhere, Category="MontageVisibilityData", meta=(EditCondition="Rule == EMontageVisibilityRule::MetaTagQuery", EditConditionHides))
	FGameplayTagQuery TagQuery;

};

USTRUCT()
struct FSectionNameAndWeight
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SectionNameAndWeight")
	FName SectionName;

	UPROPERTY(EditAnywhere, Category="SectionNameAndWeight")
	float SectionWeight;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition", "Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UFortMontageItemDefinitionBase : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Emote")
	bool CanAccessMontageItem(const AFortPlayerController* FortPC) const;

	UFUNCTION(BlueprintPure, Category="Emote")
	bool CanActivateMontageItem(const AFortPlayerController* FortPC, FGameplayTagContainer& OutFailureTags) const;

	UFUNCTION(BlueprintPure, Category="Emote")
	bool CanShowMontageItem(const FFortAthenaLoadout& Loadout) const;

	UFUNCTION(BlueprintPure, Category="Emote")
	TSoftObjectPtr<UAnimMontage> GetAnimation(EFortCustomBodyType::Type BodyType, EFortCustomGender::Type Gender, AFortPlayerPawn* PawnContext) const;

	UFUNCTION(BlueprintPure, Category="Emote")
	UAnimMontage* GetAnimationHardReference(EFortCustomBodyType::Type BodyType, EFortCustomGender::Type Gender, AFortPlayerPawn* PawnContext) const;

	UFUNCTION(BlueprintPure, Category="Emote")
	virtual TSoftObjectPtr<UAnimMontage> GetFrontendPreviewAnimation(EFortCustomBodyType::Type BodyType, AFortPlayerPawn* PreviewPawn, EFortCustomGender::Type Gender) const;

	UFUNCTION(BlueprintPure, Category="Emote")
	UAnimMontage* GetFrontendPreviewAnimationHardReference(EFortCustomBodyType::Type BodyType, EFortCustomGender::Type Gender, AFortPlayerPawn* PawnContext) const;

	UFUNCTION(BlueprintPure, Category="Emote")
	virtual bool HasCosmeticDrivenMotageSection() const;

	UFUNCTION(BlueprintPure, Category="Emote")
	bool IsMontageItemEmoteWheelExclusive(const AFortPlayerController* FortPC) const;

	UFUNCTION(BlueprintPure, Category="Emote")
	virtual FName PickCosmeticDrivenSectionByName(AFortPawn* PawnPlayingMotage) const;

	UFUNCTION(BlueprintPure, Category="Emote")
	FName PickMontageSection(const UAnimMontage* Montage, AFortPawn* FortPawn) const;

	UFUNCTION(BlueprintPure, Category="Emote")
	FName PickRandomSectionByName(float RandomNumber) const;

	UFUNCTION(BlueprintPure, Category="Emote")
	bool ShouldHolsterWeapon(AFortPawn* FortPawn) const;

	UFUNCTION(BlueprintPure, Category="Emote")
	bool ShouldPlayRandomSectionByName() const;

protected:
	UFUNCTION(Category="Emote", meta=(CallInEditor="true"))
	void PreviewInPIE();

	UPROPERTY(EditAnywhere, Category="Emote", meta=(AssetBundles="AvatarDisplay"))
	TSoftObjectPtr<UAnimMontage> Animation;

	UPROPERTY(EditAnywhere, Category="Emote", meta=(AssetBundles="AvatarDisplay"))
	TSoftObjectPtr<UAnimMontage> AnimationFemaleOverride;

	UPROPERTY(EditAnywhere, Category="Emote", meta=(AssetBundles="AvatarDisplay"))
	TArray<FFortEmoteMapping> AnimationOverrides;

	UPROPERTY(EditAnywhere, Category="Emote")
	int32 PreviewLoops;

	UPROPERTY(EditAnywhere, Category="Emote")
	float PreviewLength;

	UPROPERTY(EditAnywhere, Category="Emote")
	bool bIncludeAudioWithAnimDuration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	float EmoteCooldownSecs;

	UPROPERTY(EditAnywhere, Category="Emote")
	bool bMontageContainsFacialAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	bool bPlayRandomSection;

	UPROPERTY(EditAnywhere, Category="Emote", meta=(TitleProperty="SectionName"))
	TArray<FSectionNameAndWeight> PlayRandomSectionByName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	bool bSwitchToHarvestingToolOnUse;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	bool bHolsterWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote", meta=(DisplayName="Holster Weapon Except Standard Pickaxe"))
	bool bHolsterWeaponIfDualWieldPickaxe;

	UPROPERTY(EditAnywhere, Category="Emote")
	TArray<FMontageItemAccessData> AccessData;

	UPROPERTY(EditAnywhere, Category="Emote")
	TArray<FMontageVisibilityData> VisibilityData;

	UPROPERTY(EditAnywhere, Category="Emote")
	FGameplayTagContainer EmoteWheelExclusiveTags;

	UPROPERTY(EditAnywhere, Category="Emote", meta=(AssetBundles="AvatarDisplay"))
	TSoftObjectPtr<UAthenaCosmeticItemDefinition> RequiredEmoteParent;

	UPROPERTY(EditAnywhere, Category="Emote")
	TArray<FMcpVariantChannelInfo> EmoteParentVariants;

	UPROPERTY(EditAnywhere, Category="Emote")
	FGameplayTagContainer TagsWhichIndicateEmoteParent;

	UPROPERTY(EditDefaultsOnly, Category="Emote")
	FText CustomBuiltInExclusiveCallout;

};

