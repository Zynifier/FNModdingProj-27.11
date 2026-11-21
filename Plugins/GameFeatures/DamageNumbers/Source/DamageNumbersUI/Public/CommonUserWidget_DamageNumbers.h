// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "CommonUserWidget_DamageNumbers.generated.h"

class AActor;
class UCommonTextBlock;
class UCommonUserWidget_DamageNumbers;
class UImage;
class UWidgetAnimation;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFinishedAnimating, UCommonUserWidget_DamageNumbers*, Widget);

UCLASS()
class DAMAGENUMBERSUI_API UCommonUserWidget_DamageNumbers : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OnDamageDealt(double InDamage, AActor* InActor, bool bInShield, bool bInCrit, FVector InWorldSpacePos, bool bInEMP);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnShieldBreak(bool bIsOvershield);

	UFUNCTION(BlueprintCallable)
	void Reset();

	UFUNCTION(BlueprintCallable)
	void UpdateScreenSpacePosition();

	UPROPERTY(BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FVector WorldSpacePos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FGameplayTag CheckAnimalTag;

	UPROPERTY(BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	float Damage;

	UPROPERTY(BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	float AdditionalVerticalScreenOffset;

	UPROPERTY(BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	double SpawnTime;

	UPROPERTY(BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FVector2D DamageNumberScaleVector;

	UPROPERTY(BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FVector2D ScreenSpaceOffsetFromHitActor;

	UPROPERTY(BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FVector2D InverseHUDScaleVector;

	UPROPERTY(BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	TObjectPtr<AActor> HitActor;

	UPROPERTY(BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	bool bHitAnimal;

	UPROPERTY(BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	bool bHitVehicle;

	UPROPERTY(BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	bool bIsPlayingCritAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FLinearColor HitColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FLinearColor VehicleColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FLinearColor CritColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FLinearColor HealthColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FLinearColor ShieldColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FLinearColor CritColor_Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FLinearColor ShieldColor_Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FLinearColor HealthColor_InnerStroke;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FLinearColor ShieldColor_InnerStroke;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FLinearColor CritColor_InnerStroke;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FLinearColor DamageIconVehicleColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FLinearColor DamageIconShieldColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FLinearColor DamageIconShieldOutline1Color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FLinearColor DamageIconShieldOutline2Color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FLinearColor DamageIconVehicleOutline1Color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CommonUserWidget_DamageNumbers")
	FLinearColor DamageIconVehicleOutline2Color;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CommonUserWidget_DamageNumbers", meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> OnDamage;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CommonUserWidget_DamageNumbers", meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> OnDamage_Crit;

	UPROPERTY(BlueprintReadWrite, Export, Category="CommonUserWidget_DamageNumbers", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Number;

	UPROPERTY(BlueprintReadWrite, Export, Category="CommonUserWidget_DamageNumbers", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Number_Stroke;

	UPROPERTY(BlueprintReadWrite, Export, Category="CommonUserWidget_DamageNumbers", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> DamageTypeCrit;

	UPROPERTY(BlueprintReadWrite, Export, Category="CommonUserWidget_DamageNumbers", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> DamageTypeIcon;

	UPROPERTY(BlueprintReadWrite, Export, Category="CommonUserWidget_DamageNumbers", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> DamageTypeIcon_EMP;

};

