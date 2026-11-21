// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAIAnimInstance.h"
#include "FortAIAnimInstance_Caretaker.generated.h"

class UFortAnimWorldStriderComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortAIAnimInstance_Caretaker : public UFortAIAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetStartAnimPosition() const;

	UFUNCTION(BlueprintPure)
	float GetWalkPlayRateValue() const;

	UFUNCTION(BlueprintPure)
	float GetWalkSpeedWarpingValue() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintThreadSafe))
	virtual UFortAnimWorldStriderComponent* GetWorldStriderComponent() const;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transient Properties")
	bool bIsMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transient Properties")
	float WalkPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transient Properties")
	float AimOffsetCurve;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transient Properties")
	bool bFootPhase_StopLeftPlant;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transient Properties")
	bool bFootPhase_StopLeftPass;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transient Properties")
	bool bFootPhase_StopRightPlant;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transient Properties")
	bool bFootPhase_StopRightPass;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transient Properties")
	float BreathingCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float MovingTreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FName CurveName_AimOffsetCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FName CurveName_FootPhase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FName CurveName_BreathingCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FName SocketName_FX_Chest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FName ParamName_ChestSocketLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FName ParamName_ChestSocketVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float FirstFootPhaseMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float SecondFootPhaseMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float ThirdFootPhaseMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float FourthFootPhaseMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float FootPhaseMax;

protected:
	UFUNCTION(BlueprintCallable, Category="Materials")
	void SetDelayedMaterialParameters();

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Export, Category="World Strider", meta=(AllowPrivateAccess="true", BlueprintProtected="true", EditInline="true"))
	TObjectPtr<UFortAnimWorldStriderComponent> WorldStriderComponent;

};

