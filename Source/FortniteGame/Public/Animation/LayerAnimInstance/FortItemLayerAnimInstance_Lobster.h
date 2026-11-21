// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/LayerAnimInstance/FortItemLayerAnimInstance.h"
#include "FortItemLayerAnimInstance_Lobster.generated.h"

class UAnimSequence;

USTRUCT(BlueprintType)
struct FFortMeleeDeflectTransitionAnimData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="MeleeDeflectAnim")
	TObjectPtr<UAnimSequence> TransitionAnim;

	UPROPERTY(EditDefaultsOnly, Category="MeleeDeflectAnim")
	int32 NextDeflectDataIndex;

};

USTRUCT(BlueprintType)
struct FFortMeleeDeflectAnimData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="MeleeDeflectAnim")
	TObjectPtr<UAnimSequence> EntryFromGuardAnim;

	UPROPERTY(EditDefaultsOnly, Category="MeleeDeflectAnim")
	TObjectPtr<UAnimSequence> HoldAnim;

	UPROPERTY(EditDefaultsOnly, Category="MeleeDeflectAnim")
	TObjectPtr<UAnimSequence> ExitToGuardAnim;

	UPROPERTY(EditDefaultsOnly, Category="MeleeDeflectAnim")
	TArray<FFortMeleeDeflectTransitionAnimData> TransitionsToNextDeflection;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortItemLayerAnimInstance_Lobster : public UFortItemLayerAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AnimNotify_DeflectHold1Entered();

	UFUNCTION()
	void AnimNotify_DeflectHold2Entered();

	UFUNCTION()
	void AnimNotify_GuardLoopEntered();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	FRotator RootRotationOffset;

	UPROPERTY(EditDefaultsOnly, Category="MeleeDeflectAnim")
	TArray<FFortMeleeDeflectAnimData> MeleeDeflectAnimData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	TObjectPtr<UAnimSequence> DeflectEntry1Anim;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	TObjectPtr<UAnimSequence> DeflectHold1Anim;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	TObjectPtr<UAnimSequence> DeflectExit1Anim;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	TObjectPtr<UAnimSequence> DeflectTransition1_2Anim;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	TObjectPtr<UAnimSequence> DeflectHold2Anim;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	TObjectPtr<UAnimSequence> DeflectExit2Anim;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	TObjectPtr<UAnimSequence> DeflectTransition2_1Anim;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	int32 ActiveDeflectionIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	int32 NextDeflectionIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	bool bIsMeleeGuarding;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	bool bIsMeleeDeflecting;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	bool bIsMeleeDodging;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	bool bIsMeleeDodgingNorth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	bool bIsMeleeDodgingSouth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	bool bIsMeleeDodgingWest;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	bool bIsMeleeDodgingEast;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_Lobster")
	bool bIsDoubleJumping;

};

