// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Animation/FortEmoteMapping.h"
#include "Cosmetics/Items/FortMontageItemDefinitionBase.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "FortCustomPartTypeEnum.h"
#include "AthenaDanceItemDefinition.generated.h"

class UAnimMontage;
class UAthenaDanceItemDefinition;
class UCustomCharacterPart;
class UFortGameplayAbility;
class UFortItemDefinition;

UENUM()
enum class EMontageSelectionPredicateType : uint8
{
	// legacy default value. If seen, please select an alternate mode.

	NotSet = 0 UMETA(Hidden),
	// the meta tag requirements of the montage section will be evaluated

	MetaTags = 1,
	// the character part requirements of the montage section will be evaluated

	CharacterParts = 2,
	// the active swap requirements of the montage section will be evaluated

	ActiveSwapPresence = 3,
	// new default - should never be serialized

	Invalid = 4 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FVariantSwapMontageActiveSwapsRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="VariantSwapMontageActiveSwapsRequirement")
	TArray<FMcpVariantChannelInfo> VariantSelections;

	UPROPERTY(EditAnywhere, Category="VariantSwapMontageActiveSwapsRequirement")
	TObjectPtr<UFortItemDefinition> Item;

};

USTRUCT(BlueprintType)
struct FVariantSwapMontagePartRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="VariantSwapMontagePartRequirement")
	TEnumAsByte<EFortCustomPartType::Type> PartType;

	UPROPERTY(EditAnywhere, Category="VariantSwapMontagePartRequirement")
	TSoftObjectPtr<UCustomCharacterPart> Part;

};

USTRUCT(BlueprintType)
struct FVariantSwapMontageData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="VariantSwapMontageData")
	FName MontageSectionName;

	UPROPERTY(EditAnywhere, Category="Condition", meta=(InlineCategoryProperty))
	EMontageSelectionPredicateType EvaluationMode;

	UPROPERTY(EditAnywhere, Category="Condition", meta=(EditCondition="EvaluationMode == EMontageSelectionPredicateType::MetaTags || EvaluationMode == EMontageSelectionPredicateType::NotSet && !bRequireCharacterPart", EditConditionHides))
	FGameplayTag VariantMetaTagRequired;

	UPROPERTY()
	bool bRequireCharacterPart;

	UPROPERTY(EditAnywhere, Category="Condition", meta=(EditCondition="EvaluationMode == EMontageSelectionPredicateType::CharacterParts || EvaluationMode == EMontageSelectionPredicateType::NotSet && bRequireCharacterPart", EditConditionHides))
	TArray<FVariantSwapMontagePartRequirement> PartRequirements;

	UPROPERTY(EditAnywhere, Category="Condition", meta=(EditCondition="EvaluationMode == EMontageSelectionPredicateType::ActiveSwapPresence", EditConditionHides))
	TArray<FVariantSwapMontageActiveSwapsRequirement> SwapRequirements;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition", "Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaDanceItemDefinition : public UFortMontageItemDefinitionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Emote")
	FText GetChatTriggerCommandName() const;

	UFUNCTION(BlueprintPure)
	TSoftClassPtr<UFortGameplayAbility> GetCustomDanceAbility() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	uint8 bUsesSecondaryFireInput : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	uint8 bMovingEmote : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	uint8 bMovingEmoteSkipLandingFX : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	uint8 bMoveForwardOnly : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	uint8 bMoveFollowingOnly : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	uint8 bGroupEmote : 1;

	UPROPERTY(EditAnywhere, Category="Emote")
	uint8 bUseHighPreviewCamera : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	uint8 bGroupAnimationSync : 1;

	UPROPERTY(EditAnywhere, Category="Emote")
	uint8 bAllowLowerBodyLocomotion : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	float WalkForwardSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	float GroupSyncAnimOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	TObjectPtr<UAthenaDanceItemDefinition> GroupEmoteToStartLeader;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	TObjectPtr<UAthenaDanceItemDefinition> GroupEmoteToStartFollower;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	TObjectPtr<UAthenaDanceItemDefinition> GroupEmoteToStartLeaderIfBothOwn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	TObjectPtr<UAthenaDanceItemDefinition> GroupEmoteToStartFollowerIfBothOwn;

	UPROPERTY(EditAnywhere, Category="Emote")
	TArray<FVariantSwapMontageData> MotageSelectionGroups;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	FVector GroupEmotePositionOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	float GroupEmotePositionOffsetTolerance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	float GroupEmoteFollowDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	bool bLockGroupEmoteLeaderRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	float GroupEmoteLeaderRotationYawOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	float GroupEmoteFollowerRotationYawOffset;

	UPROPERTY(EditAnywhere, Category="Emote", meta=(AssetBundles="AvatarDisplay"))
	TSoftObjectPtr<UAnimMontage> FrontEndAnimation;

	UPROPERTY(EditAnywhere, Category="Emote", meta=(AssetBundles="AvatarDisplay"))
	TSoftObjectPtr<UAnimMontage> FrontEndAnimationFemaleOverride;

	UPROPERTY(EditAnywhere, Category="Emote", meta=(AssetBundles="AvatarDisplay"))
	TArray<FFortEmoteMapping> FrontEndAnimationOverrides;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Emote")
	uint8 bUseMetaTagsFromPickaxeActor : 1;

protected:
	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftClassPtr<UFortGameplayAbility> CustomDanceAbility;

private:
	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="Emote")
	FText ChatTriggerCommandName;

};

