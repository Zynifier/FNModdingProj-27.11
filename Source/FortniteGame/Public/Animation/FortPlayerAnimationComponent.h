// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Animation/AnimInputs/FortAnimInput_SpringGlider.h"
#include "Animation/FortAnimInputs.h"
#include "FortPlayerAnimationComponent.generated.h"

class AFortPawn;
class UFortAnimDebugManager;
class UFortItemDefinition;
class UFortPlayerAnimationInterface;

USTRUCT()
struct FAnimInput_Defaults
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FFortAnimInput_Quad QuadBikeInput;

	UPROPERTY(Transient)
	FFortAnimInput_GolfCart GolfCartInput;

	UPROPERTY(Transient)
	FFortAnimInput_FerretVehicle FerretVehicleInput;

	UPROPERTY(Transient)
	FFortAnimInput_JackalVehicle JackalVehicleInput;

	UPROPERTY(Transient)
	FFortAnimInput_Motorcycle MotorcycleInput;

	UPROPERTY(Transient)
	FFortAnimInput_TurnInPlace TurnInPlaceInput;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("ComponentTick", "ComponentReplication", "Replication", "Events", "Activation", "Cooking", "AssetUserData", "Collision", "Sockets", "Tags"))
class UFortPlayerAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Montages")
	float DefaultFullBodyToUpperBodyInMotionBlendTime;

private:
	UFUNCTION()
	void OnBeginSkydiving();

	UFUNCTION()
	void OnPawnStartedEmote(const UFortItemDefinition* MontageItemDef, AFortPawn* PawnEmoting);

	UFUNCTION()
	void OnPawnStoppedEmote(const UFortItemDefinition* MontageItemDef, AFortPawn* PawnEmoting);

	UFUNCTION()
	void OnWeaponUnequipped();

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortPlayerAnimationInterface> AnimationInterface;

	UPROPERTY(Transient)
	FAnimInput_Defaults AnimInputDefaults;

	UPROPERTY(EditDefaultsOnly, Category="Vehicles")
	FFortAnimInput_CommonVehicle CommonVehicleInput;

	UPROPERTY(EditDefaultsOnly, Category="Vehicles")
	FFortAnimInput_Quad QuadBikeInput;

	UPROPERTY(EditDefaultsOnly, Category="Vehicles")
	FFortAnimInput_GolfCart GolfCartInput;

	UPROPERTY(EditDefaultsOnly, Category="Vehicles")
	FFortAnimInput_FerretVehicle FerretVehicleInput;

	UPROPERTY(EditDefaultsOnly, Category="Vehicles")
	FFortAnimInput_JackalVehicle JackalVehicleInput;

	UPROPERTY(EditDefaultsOnly, Category="Vehicles")
	FFortAnimInput_Motorcycle MotorcycleInput;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FFortAnimInput_Zipline ZiplineInput;

	UPROPERTY(EditDefaultsOnly, Category="Weapons")
	FFortAnimInput_BowWeapon BowWeaponInput;

	UPROPERTY(EditDefaultsOnly, Category="Skydiving")
	FFortAnimInput_Skydiving SkydivingInput;

	UPROPERTY(EditDefaultsOnly, Category="Skydiving")
	FFortAnimInput_SpringGlider SpringGliderInput;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace")
	FFortAnimInput_TurnInPlace TurnInPlaceInput;

	UPROPERTY(Transient)
	uint32 LastPreUpdateFrame;

	UPROPERTY(Transient)
	uint32 LastNativeUpdateFrame;

	UPROPERTY(Transient)
	uint32 LastPostUpdateFrame;

	UPROPERTY(Transient)
	TObjectPtr<UFortAnimDebugManager> DebugManager;

};

