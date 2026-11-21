// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerAnimAsset.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerGliderAnimAsset.h"
#include "Animation/AnimInputs/FortAnimInput_RandomizeMontageSection.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/FortBaseAnimInstance.h"
#include "Animation/FortPlayMontageForGameplayTagQueryInterface.h"
#include "Customization/GameplayTagAnimation.h"
#include "FortGender.h"
#include "FrontendAnimInstance.generated.h"

class AFortPlayerParachute;
class AFortPlayerPawn;
class AFortWeapon;
class UAnimMontage;
class UAnimNotify;
class UFortItemDefinition;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFrontendAnimInstance : public UFortBaseAnimInstance, public IFortPlayMontageForGameplayTagQueryInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AnimNotify_PlayFireFX(const UAnimNotify* Notify);

	UFUNCTION(BlueprintCallable, Category="FrontendAnimInstance")
	EFortDisplayGender::Type GetGender();

	UFUNCTION(BlueprintCallable, Category="FrontendAnimInstance")
	bool IsInLobby();

	UFUNCTION(BlueprintCallable, Category="FrontendAnimInstance")
	void PlayIntro();

	UFUNCTION(BlueprintCallable, Category="FrontendAnimInstance")
	void PlayOutro();

	UFUNCTION(BlueprintCallable, Category="FrontendAnimInstance")
	void PlaySelected();

	UFUNCTION(BlueprintPure, Category="FrontendAnimInstance")
	bool ShouldHidePropsDuringBlend(UAnimMontage* Montage) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Skydiving")
	bool bIsSkydiving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Skydiving")
	bool bIsSkydiveDiving;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	float ContrailDiveFactor;

	UPROPERTY(EditAnywhere, Category="IK")
	bool bEnableHandIK;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Emotes")
	bool bIsPlayingEmote;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FrontendAnimInstance")
	bool bIsBodyTypeManuallySet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FrontendAnimInstance")
	uint8 bLookingAtBackpack : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FrontendAnimInstance")
	uint8 bIsRebirth : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PelvisAdjustment")
	FFortAnimInput_PelvisAdjustment PelvisAdjustmentInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HandIK")
	FFortAnimInput_HandIK HandIKInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortPlayerPawn")
	EFortPlayerAnimBodyType AnimBodyType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FacialAnim")
	FFortAnimInput_Facial FacialInput;

	UPROPERTY()
	FFortAnimInput_RandomizeMontageSection RandomizeMontageSectionInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="IK")
	float HandIKRetargetingWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="IK")
	float RightHandIKAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="IK")
	float LeftHandIKAlpha;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient, Category="Idle")
	float IdlePelvisOffsetAlpha;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient, Category="Idle")
	FVector IdlePelvisOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Emote")
	float EmoteHipOffsetAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	float EmoteHipOffsetInterpSpeed;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFocusedItemChanged(const UFortItemDefinition* FocusedItem, const AFortWeapon* EquippedWeapon, const AFortPlayerParachute* CurrentParachute);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayMontageFromGameplayTagQuery(const FGameplayTagQuery& MatchingQuery, UAnimMontage* MontagePlaying);

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	TObjectPtr<AFortPlayerPawn> FortPlayerPawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FrontendAnimInstance")
	TEnumAsByte<EFortDisplayGender::Type> Gender;

	UPROPERTY(EditDefaultsOnly, Category="FrontendAnimInstance")
	TObjectPtr<UAnimMontage> IntroAnimation_Female;

	UPROPERTY(EditDefaultsOnly, Category="FrontendAnimInstance")
	TObjectPtr<UAnimMontage> IntroAnimation_Male;

	UPROPERTY(EditDefaultsOnly, Category="FrontendAnimInstance")
	TObjectPtr<UAnimMontage> OutroAnimation_Female;

	UPROPERTY(EditDefaultsOnly, Category="FrontendAnimInstance")
	TObjectPtr<UAnimMontage> OutroAnimation_Male;

	UPROPERTY(EditDefaultsOnly, Category="FrontendAnimInstance")
	TObjectPtr<UAnimMontage> SelectedAnimation_Female;

	UPROPERTY(EditDefaultsOnly, Category="FrontendAnimInstance")
	TObjectPtr<UAnimMontage> SelectedAnimation_Male;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FrontendAnimInstance")
	uint8 bCanPlayCustomAnimations : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FrontendAnimInstance")
	uint8 bDontCrossArms : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FrontendAnimInstance")
	uint8 bNoHandsOnHips : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FrontendAnimInstance")
	FGameplayTagAnimations GameplayTagAnimations;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FrontendAnimInstance")
	FGameplayTagAnimations FemaleGameplayTagAnimations;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FrontendAnimInstance")
	FGameplayTagAnimations MaleGameplayTagAnimations;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimSets")
	FFortAnimInput_StandingPawnAnimAsset CurrentAnimSet;

	UPROPERTY(EditAnywhere, Category="AnimSets")
	FFortAnimInput_StandingPawnAnimAsset DefaultAnimSetMale;

	UPROPERTY(EditAnywhere, Category="AnimSets")
	FFortAnimInput_StandingPawnAnimAsset DefaultAnimSetFemale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimSets")
	FFortAnimInput_PlayerGliderAnimAsset CurrentGliderAnimSet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	FFortAnimInput_Skydiving Skydiving;

};

