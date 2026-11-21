// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "FortNevadaAudioController.generated.h"

class AFortNevadaVehicle;
class UFortLayeredAudioComponent;

USTRUCT()
struct FNevadaAudioUpdateContext
{
	GENERATED_BODY()

};

UCLASS(Config=Game, BlueprintType, Blueprintable)
class AFortNevadaAudioController : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="AudioController")
	void BP_Init();

	UFUNCTION(BlueprintImplementableEvent, Category="AudioController")
	void BP_Update();

	UFUNCTION(BlueprintCallable, Category="AudioController")
	void CacheReferences(UFortLayeredAudioComponent* InLayeredAudioComponent);

	UFUNCTION(BlueprintPure, Category="AudioController")
	AFortNevadaVehicle* GetVehicleActor() const;

	UFUNCTION(Category="AudioController")
	void Init(AFortNevadaVehicle* InVehicle);

	UFUNCTION(Category="AudioController")
	void Update();

	UPROPERTY(EditDefaultsOnly, Category="ParamRanges")
	FVector2D SpeedRangeMap;

	UPROPERTY(EditDefaultsOnly, Category="ParamRanges")
	FVector2D TurningRangeMap;

	UPROPERTY(EditDefaultsOnly, Category="ParamRanges")
	FVector2D AcceleratingRangeMap;

	UPROPERTY(EditDefaultsOnly, Category="ParamRanges")
	FVector2D BrakingRangeMap;

	UPROPERTY(EditDefaultsOnly, Category="ParamRanges")
	FVector2D PassByRangeMap;

	UPROPERTY(EditDefaultsOnly, Category="ParamRanges")
	FVector2D LFORangeMap;

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortNevadaVehicle> Vehicle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> LayeredAudioComponent;

	UPROPERTY(BlueprintReadOnly, Category="Vehicle")
	float SpeedParamValue;

	UPROPERTY(BlueprintReadOnly, Category="Vehicle")
	float SpeedParamValuePrev;

	UPROPERTY(BlueprintReadOnly, Category="Vehicle")
	float AcceleratingParamValue;

	UPROPERTY(BlueprintReadOnly, Category="Vehicle")
	float BrakingParamValue;

	UPROPERTY(BlueprintReadOnly, Category="Vehicle")
	FVector ForwardVector;

	UPROPERTY(BlueprintReadOnly, Category="Vehicle")
	FVector ForwardVectorPrev;

	UPROPERTY(BlueprintReadOnly, Category="Vehicle")
	float TurningParamValue;

	UPROPERTY(BlueprintReadOnly, Category="Vehicle")
	float PassByParamValue;

	UPROPERTY(BlueprintReadOnly, Category="Vehicle")
	float LocallyControlledParamValue;

	UPROPERTY(BlueprintReadOnly, Category="Vehicle")
	float LFOParamValue;

};

