// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CRDPlayerTrackerMarker.generated.h"

class AFortPlayerControllerGameplay;
class AFortPlayerStateAthena;
class UActorComponent;
class UUserWidget;

UCLASS(Config=Creative, BlueprintType, Blueprintable, ClassGroup=("Creative"))
class ACRDPlayerTrackerMarker : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Player Tracker")
	UUserWidget* CreatePlayerTrackerWidget(AFortPlayerControllerGameplay* InFortPlayerControllerGameplay, AFortPlayerStateAthena* AssociatedPSA);

	UFUNCTION(BlueprintCallable, Category="Player Tracker")
	bool DestroyPlayerTrackerWidget(AFortPlayerControllerGameplay* InFortPlayerControllerGameplay);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI")
	TSubclassOf<UUserWidget> WidgetClass;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UActorComponent> PlayerTrackerUIActorComponent;

};

