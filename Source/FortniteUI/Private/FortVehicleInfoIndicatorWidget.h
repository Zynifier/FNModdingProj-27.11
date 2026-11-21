// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortActorIndicatorWidget.h"
#include "FortVehicleInfoIndicatorWidget.generated.h"

class AActor;
class APawn;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI", ClassGroup="UI", DisableNativeTick))
class UFortVehicleInfoIndicatorWidget : public UFortActorIndicatorWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	APawn* GetControlledPawn() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnVehicleChanged();

	UFUNCTION(BlueprintNativeEvent)
	void OnVehicleHealthChanged();

	UFUNCTION(BlueprintCallable)
	void SetVehicle(AActor* NewVehicle);

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortVehicleInfoIndicatorWidget")
	TWeakObjectPtr<AActor> CurrentVehicle;

	UPROPERTY(EditDefaultsOnly, Category="FortVehicleInfoIndicatorWidget")
	float TimeToHideWhenDamaged;

};

