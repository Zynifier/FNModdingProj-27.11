// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Athena/AthenaCoupledWidgetInterface.h"
#include "OstrichFinaleWidget.generated.h"

class AFortCharacterVehicle_Ostrich;

UCLASS()
class UOstrichFinaleWidget : public UUserWidget, public IAthenaCoupledWidgetInterface
{
	GENERATED_BODY()

public:
	UOstrichFinaleWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCancelSelfDestructPrime();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSelfDestructFinish();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSelfDestructStart(float WarningDuration);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartSelfDestructPrime(float Duration);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateSelfDestruct(float RemainingTime);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Visuals")
	float DestructDisplayUpdateFrequency;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Visuals")
	float FinishBroadcastOffset;

	UPROPERTY(BlueprintReadOnly, Category="OstrichFinaleWidget")
	TObjectPtr<AFortCharacterVehicle_Ostrich> OwningVehicle;

};

