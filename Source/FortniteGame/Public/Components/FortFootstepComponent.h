// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Components/FortPawnComponent.h"
#include "Sound/FortFootstepBank.h"
#include "FortFootstepComponent.generated.h"

class AActor;
class AFortPawn;
class UFortFootstepAudioBank;
class UFortPlayerFoleyContext;
class UFortSurfaceTrackingComponent;
class USoundBase;

UENUM(BlueprintType)
enum class EFortFootstepPlayerRelation : uint8
{
	LocalPlayer = 0,
	Friendly = 1,
	Enemy = 2,
	Max_None = 3 UMETA(DisplayName="Game Defined"),
};

UENUM(BlueprintType)
enum class EFortFootstepStanceType : uint8
{
	Walk = 0,
	Run = 1,
	Sprint = 2,
	CrouchWalk = 3,
	CrouchRun = 4,
	Max_None = 5 UMETA(Displayname="Game Defined"),
};

UENUM(BlueprintType)
enum class EFortFootstepSurface : uint8
{
	Dirt = 0,
	Grass = 1,
	Metal = 2,
	Sand = 3,
	Snow = 4,
	Ice = 5,
	Stone = 6,
	Water = 7,
	Wood = 8,
	Chrome = 9,
	ChromePetrified = 10,
	Mud = 11,
	WetConcrete = 12,
	TreeCanopy = 13,
	Max_None = 14 UMETA(Displayname="Game Defined"),
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("ComponentTick", "Collision", "Trigger", "PhysicsVolume"), ClassGroup=("AudioGameplay"), meta=(BlueprintSpawnableComponent))
class UFortFootstepComponent : public UFortPawnComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Movement Audio")
	EFortFootstepSurfaceType::Type GetSurfaceType() const;

	UFUNCTION(BlueprintCallable, Category="Audio")
	void PlayFootstep(int32 FootDown);

	UPROPERTY()
	TObjectPtr<UFortFootstepAudioBank> FootstepBank;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio")
	float MaxFootstepDistance;

	UPROPERTY()
	TObjectPtr<USoundBase> DefaultFootstepSound;

	UPROPERTY()
	TObjectPtr<USoundBase> DefaultFastFootstepSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio|Legacy")
	TObjectPtr<USoundBase> DBNOLandingSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio|Legacy")
	TObjectPtr<USoundBase> DefaultLandingSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio|Legacy")
	TObjectPtr<USoundBase> DefaultHardLandingSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio|Legacy")
	TObjectPtr<USoundBase> DefaultCrouchSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio|Legacy")
	TObjectPtr<USoundBase> DefaultStandSound;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFootstepComponent")
	TEnumAsByte<EFortFootstepSurfaceType::Type> SurfaceType;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFootstepComponent")
	EFortFootstepSurface FootstepSurface;

	UPROPERTY(EditAnywhere, Category="SurfaceMapping", meta=(ArraySizeEnum="/Script/PhysicsCore.EPhysicalSurface"))
	EFortFootstepSurface PhysicalSurfaces[35];

protected:
	UFUNCTION()
	void HandleSurfaceTypeChanged(AActor* SurfaceActor, EPhysicalSurface CurrentSurfaceType, EPhysicalSurface PrevSurfaceType);

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TSubclassOf<UFortPlayerFoleyContext> PlayerFoleyContextClass;

	UPROPERTY(Transient)
	TObjectPtr<UFortPlayerFoleyContext> PlayerFoleyContext;

	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> OwningPawn;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortSurfaceTrackingComponent> SurfaceTrackingComponent;

};

