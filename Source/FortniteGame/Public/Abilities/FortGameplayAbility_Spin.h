// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Abilities/FortGameplayAbility_Action.h"
#include "FortGameplayAbility_Spin.generated.h"

class UFortPawnSpinParamsObj;
class UObject;

USTRUCT(BlueprintType)
struct FFortPawnSpinParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spin")
	float LocalSpin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spin")
	bool bOnlySpinWhenFalling;

};

UCLASS()
class UFortGameplayAbility_Spin : public UFortGameplayAbility_Action
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable)
class UFortPawnSpinParamsObj : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Spin", meta=(DefaultToSelf="WorldContextObject", DisplayName="Create FortPawnSpinParamsObj Instance", HidePin="WorldContextObject"))
	static UFortPawnSpinParamsObj* BP_CreateFortPawnSpinParamsObjInstance(UObject* WorldContextObject);

	UPROPERTY(Replicated)
	uint8 bReplicatedFlag : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spin")
	FFortPawnSpinParams SpinParams;

};

