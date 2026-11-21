// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "FortClientSettingsRecord.h"
#include "FortUserWidget.h"
#include "FortUserWidget_HitTicks.generated.h"

class AActor;
class UImage;
class UWidgetAnimation;

UCLASS()
class HITTICKSUI_API UFortUserWidget_HitTicks : public UFortUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void HudScaleChanged();

	UFUNCTION(BlueprintCallable)
	void OnDisplayHitNotify(double InDamage, bool bInCritical, bool bInFatal, bool bInShield, AActor* InPawn, FVector HitLocation, FGameplayTagContainer Tags);

	UFUNCTION(BlueprintCallable)
	void OnPawnSet();

	UFUNCTION(BlueprintCallable)
	void OnReticleSettingsChanged();

	UFUNCTION()
	void OnShieldBreak(bool bInOverShield);

	UFUNCTION(BlueprintCallable)
	void UpdateTickMarkerOpacity(float NewOpacity);

	UPROPERTY(BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	bool bShield;

	UPROPERTY(BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	double HitTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	double ShieldHitTime;

	UPROPERTY(BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	double TimeSinceHit;

	UPROPERTY(EditDefaultsOnly, Category="FortUserWidget_HitTicks")
	double HitInterval;

	UPROPERTY(EditDefaultsOnly, Category="FortUserWidget_HitTicks")
	double ShieldIconMaxAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUserWidget_HitTicks")
	double FadeDuration;

	UPROPERTY(BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	double AccumulatedDamage;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortUserWidget_HitTicks", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> HitMarker;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortUserWidget_HitTicks", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> ShieldIcon;

	UPROPERTY(BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	EHitFeedbackMode CurrentHitFeedbackMode;

	UPROPERTY(BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	bool bUseNative;

	UPROPERTY()
	TObjectPtr<AActor> PrevHitPawn;

	UPROPERTY(BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	double Damage;

	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_Elimination2;

	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_ShieldCrack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	FLinearColor BaseColor_BG1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	FLinearColor ShieldColor_BG1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	FLinearColor CritColor_BG1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	FLinearColor ElimColor_BG1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	FLinearColor BaseColor_BG2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	FLinearColor ShieldColor_BG2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	FLinearColor CritColor_BG2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	FLinearColor ElimColor_BG2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	FLinearColor BaseColor_Outline1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	FLinearColor ShieldColor_Outline1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	FLinearColor CritColor_Outline1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	FLinearColor ElimColor_Outline1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	FLinearColor BaseColor_Outline2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	FLinearColor ShieldColor_Outline2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	FLinearColor CritColor_Outline2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_HitTicks")
	FLinearColor ElimColor_Outline2;

	UPROPERTY(EditDefaultsOnly, Category="FortUserWidget_HitTicks")
	FGameplayTag UseNativeMarkerTag;

};

