// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortUIExtension.h"
#include "FortUIExtensionSlot.h"
#include "FortGameFrameworkComponent_EventMode.generated.h"

class AActor;
class APawn;
class UFortWeaponItemDefinition;
class UInputComponent;
class UUserWidget;
class UWidget;

UENUM()
enum class EFortEventModeEmoteToPlay : uint8
{
	Emote1 = 0,
	Emote2 = 1,
	Emote3 = 2,
	RandomEmote = 3,
	QuickEmotes = 4,
};

USTRUCT()
struct FEventModeFocusActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EventModeFocusActor")
	TSoftObjectPtr<AActor> Target;

	UPROPERTY(EditAnywhere, Category="EventModeFocusActor")
	float Distance;

	UPROPERTY(EditAnywhere, Category="EventModeFocusActor")
	FVector Offset;

	UPROPERTY(EditAnywhere, Category="EventModeFocusActor")
	float FOV;

};

USTRUCT()
struct FEventModeWidgetCachedData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EUIExtensionSlot Slot;

	UPROPERTY(Export)
	TWeakObjectPtr<UUserWidget> Widget;

};

UCLASS(Config=game, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameFrameworkComponent_EventMode : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortGameFrameworkComponent_EventMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	bool GetIsEventModeActive() const;

	UFUNCTION(BlueprintPure)
	bool GetIsFocusAvailable() const;

	UFUNCTION(BlueprintPure)
	bool GetIsFocusing() const;

protected:
	UPROPERTY(EditAnywhere, Category="FortGameFrameworkComponent_EventMode")
	TSoftObjectPtr<UFortWeaponItemDefinition> ActivatorAsset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameFrameworkComponent_EventMode")
	TArray<FUIExtension> UIExtensions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameFrameworkComponent_EventMode")
	TMap<FGameplayTag, TSoftClassPtr<UWidget>> TaggedUIExtensions;

	UPROPERTY(EditAnywhere, Category="FortGameFrameworkComponent_EventMode")
	TArray<FEventModeFocusActor> FocusActors;

private:
	UFUNCTION()
	void OnEnterVehicle();

	UFUNCTION()
	void OnExitVehicle();

	UFUNCTION()
	void OnPlayerPawnPossessed(APawn* PossessedPawn);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> InputComponent;

	UPROPERTY(Transient)
	TArray<FEventModeWidgetCachedData> CachedWidgetData;

	UPROPERTY(Transient)
	TSoftObjectPtr<AActor> CurrentlyFocusedActor;

};

