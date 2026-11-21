// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CarmineHUDBase.generated.h"

USTRUCT(BlueprintType)
struct FAthenaBossHealthData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaBossHealthData")
	bool bVisible;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaBossHealthData")
	bool bShowShields;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaBossHealthData")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaBossHealthData")
	int32 Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaBossHealthData")
	int32 HealthMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaBossHealthData")
	int32 Shields;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaBossHealthData")
	int32 ShieldsMax;

};

UCLASS(Abstract)
class UCarmineHUDBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UCarmineHUDBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnBossHealthBarChanged(const FAthenaBossHealthData& BossData);

};

