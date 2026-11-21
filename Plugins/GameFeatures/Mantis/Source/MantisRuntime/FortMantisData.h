// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortMantisTypes.h"
#include "FortMantisData.generated.h"

class UAnimMontage;
class UFortGameplayAbility_Mantis;

UENUM()
enum class EFortMantisTechniqueActivationInputType : uint8
{
	None = 0,
	Primary = 1,
	// Uses Primary Weapon ability

	Secondary = 2,
	// Uses Secondary Weapon Ability

	Max_Invalid = 3 UMETA(Hidden),
};

UENUM()
enum class EFortMantisTechniqueActivationTimingType : uint8
{
	None = 0 UMETA(Hidden),
	Pressed = 1,
	Released = 2,
};

UENUM()
enum class EFortMantisTechniqueAnimationType : uint8
{
	// Use a single, unchanging montage for this technique.

	SingleMontage = 0,
	// Dynamically choose a montage when this technique starts. Must set DefaultDynamicMontageName and implement UFortGameplayAbility_Mantis::GetDynamicMontageNameForTechnique.

	DynamicMontage = 1,
	// Allow the anim instance to handle the animation for this technique. Notifies from any animation sequence (not montage) will be processed.

	AnimInstance = 2,
};

UENUM()
enum class EFortMantisTechniqueRootMotionType : uint8
{
	// Don't use root motion with this technique.

	None = 0,
	// Extract root motion from the technique montage and potentially warp it to a target actor or location.

	ExtractFromMontageAndWarp = 1,
	// Apply a zero root motion source regardless of what is authored. 

	HoldPosition = 2,
};

USTRUCT()
struct FFortMantisTechniqueBranch
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueBranch")
	FName FromTechnique;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueBranch")
	FName ToTechnique;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueBranch")
	EFortMantisBranchPath BranchPath;

};

USTRUCT()
struct FFortMantisTechniqueCharacterSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueCharacterSettings")
	bool bDetachCharacterRotationFromCamera;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueCharacterSettings", meta=(ClampMin="0.010000"))
	float ReattachCharacterRotationBlendTime;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueCharacterSettings", meta=(ClampMin="0.010000"))
	float ReattachCharacterRotationBlendExponent;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueCharacterSettings", meta=(EditCondition="bDetachCharacterRotationFromCamera"))
	float WindupCharacterRotationRate;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueCharacterSettings", meta=(EditCondition="bDetachCharacterRotationFromCamera"))
	float ExecutionCharacterRotationRate;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueCharacterSettings", meta=(EditCondition="bDetachCharacterRotationFromCamera"))
	float RecoveryCharacterRotationRate;

};

USTRUCT()
struct FFortMantisTechniqueData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData")
	FName Name;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData")
	bool bStartsSequence;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData")
	bool bEndsSequence;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData")
	int32 MaxConsecutiveBranchesToSelf;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData")
	EFortMantisTechniqueAnimationType AnimationType;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData", meta=(EditCondition="AnimationType == EFortMantisTechniqueAnimationType::SingleMontage"))
	TObjectPtr<UAnimMontage> Montage;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData", meta=(EditCondition="AnimationType == EFortMantisTechniqueAnimationType::DynamicMontage"))
	TMap<FName, TObjectPtr<UAnimMontage>> DynamicMontages;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData", meta=(EditCondition="AnimationType == EFortMantisTechniqueAnimationType::DynamicMontage"))
	FName DefaultDynamicMontageName;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData")
	EFortMantisTechniqueRootMotionType RootMotionType;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData")
	float InputWindowDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData")
	EFortMantisTechniqueActivationInputType ActivationInputType;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData")
	EFortMantisTechniqueActivationTimingType ActivationTimingType;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData", meta=(EditCondition="ActivationTimingType == EFortMantisTechniqueActivationTimingType::Released"))
	float MinInputHoldDuration;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData", meta=(EditCondition="ActivationTimingType == EFortMantisTechniqueActivationTimingType::Released"))
	float MaxInputHoldDuration;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData", meta=(Categories="GameplayCue"))
	FGameplayTagContainer ActivationGameplayCues;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData")
	FGameplayTagQuery ActivationTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData")
	FGameplayTagQuery OngoingTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData")
	FGameplayTag ActivationApplicationTag;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData")
	FGameplayTag DamageApplicationTag;

	UPROPERTY(EditDefaultsOnly, Category="FortMantisTechniqueData")
	FFortMantisTechniqueCharacterSettings CharacterSettings;

};

USTRUCT(BlueprintType)
struct FFortMantisTechniqueMetadata
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortMantisTechniqueMetadata")
	TMap<FGameplayTag, int32> IntValues;

	UPROPERTY(BlueprintReadWrite, Category="FortMantisTechniqueMetadata")
	TMap<FGameplayTag, float> FloatValues;

	UPROPERTY(BlueprintReadWrite, Category="FortMantisTechniqueMetadata")
	TMap<FGameplayTag, FVector> VectorValues;

	UPROPERTY(BlueprintReadWrite, Category="FortMantisTechniqueMetadata")
	TMap<FGameplayTag, FString> StringValues;

};

UCLASS()
class UFortMantisData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Technique Settings")
	bool bShowTargetHealthBar;

	UPROPERTY(EditDefaultsOnly, Category="Technique Settings")
	TSubclassOf<UFortGameplayAbility_Mantis> TechniqueAbility;

	UPROPERTY(EditDefaultsOnly, Category="Technique Settings")
	TArray<FFortGameplayEffectContainer> TechniqueAdditionEffectContainers;

	UPROPERTY(EditDefaultsOnly, Category="Technique Settings", meta=(TitleProperty="Name"))
	TArray<FFortMantisTechniqueData> Techniques;

	UPROPERTY(EditDefaultsOnly, Category="Technique Settings")
	TArray<FFortMantisTechniqueBranch> Branches;

};

