// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "NiagaraComponentPoolMethodEnum.h"
#include "Particles/WorldPSCPool.h"
#include "CosmeticModifierInterface.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "CurieMinimalTypes.h"
#include "Customization/CustomCharacterPart.h"
#include "CustomCosmeticModifierBase.generated.h"

class AActor;
class ACharacter;
class AFortPlayerPawn;
class AFortWeapon;
class IFortVehicleInterface;
class UAthenaCosmeticItemDefinition;
class UFortItem;
class UNiagaraComponent;
class UNiagaraSystem;
class UObject;
class UParticleSystem;
class UParticleSystemComponent;
class UPrimitiveComponent;
class USceneComponent;
enum class ECosmeticModifierOutExec : uint8;
enum class EFortDayPhase : uint8;
enum class EFortItemType : uint8;

UENUM()
enum class ECosmeticModifierOutExec : uint8
{
	Success = 0,
	Failure = 1,
};

UENUM()
enum class EVehicleEnteredCosmeticReaction : uint8
{
	Driver = 0,
	Passenger = 1,
	Both = 2,
};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(ChildCanTick))
class ACustomCosmeticModifierBase : public AActor, public ICosmeticModifierInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Custom Character")
	virtual AFortPlayerPawn* GetAssociatedPlayerPawn() const;

	UFUNCTION(BlueprintCallable)
	FFortAthenaLoadout GetLoadout();

	UFUNCTION(BlueprintPure, Category="Custom Cosmetic Modifier")
	bool IsInFrontEnd() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, BlueprintCosmetic)
	void OnBeginSkydiving();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnBeginSliding();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnBeginSwimming();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnCharacterCustomizationFinished(const TArray<FAppliedCharacterPartInfo>& CharacterPartInfo);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCurieStateAttached(const FGameplayTag& Tag);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCurieStateDetached(const FGameplayTag& Tag);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnDayPhaseChanged(EFortDayPhase CurrentDayPhase, EFortDayPhase PreviousDayPhase, bool bAtCreation);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, BlueprintCosmetic)
	void OnEndSkydiving();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnEndSliding();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnEndSwimming();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnEnterVehicle(const TScriptInterface<IFortVehicleInterface>& VehicleEntered);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnExitVehicle();

	UFUNCTION()
	void OnExternalDependencyActorDestroyed(AActor* OtherActor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnHitPawn(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewPlayerWeaponType(EFortItemType NewType, EFortItemType OldType);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnNewWeapons(const TArray<UFortItem*>& WeaponsAsItems);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnPawnJumped();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnPawnLanded();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnPawnSet();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnPawnUpdated();

	UFUNCTION(BlueprintNativeEvent, BlueprintCosmetic)
	void OnPostResIn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnTargetingOrFirstPersonCameraChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnWeaponChanged(AFortWeapon* NewWeapon, AFortWeapon* OldWeapon);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, BlueprintCosmetic)
	void OnWeaponFired();

	UFUNCTION(BlueprintCallable, Category="Custom Character")
	void SetCosmeticActiveVariant(TSoftObjectPtr<UAthenaCosmeticItemDefinition> SoftCosmetic, const FGameplayTag& ChannelTag, const FGameplayTag& VariantTag);

	UFUNCTION(BlueprintCallable, Category="Part Modifier|Spawn System", meta=(AdvancedDisplay="9", DefaultToSelf="true", DisplayName="Spawn Emitter At Location Part Modifier (Legacy)", ExpandEnumAsExecs="OutExec", HideSelfPin="true", UnsafeDuringActorConstruction="true", CPP_Default_Rotation))
	UParticleSystemComponent* SpawnEmitterAtLocationPartModifier(ECosmeticModifierOutExec& OutExec, UParticleSystem* EmitterTemplate, FVector Location, FRotator Rotation, FVector Scale = FVector(1.000000, 1.000000, 1.000000), bool bAutoDestroy = true, EPSCPoolMethod PoolingMethod = EPSCPoolMethod::None, bool bAutoActivateSystem = true, bool bMatchPawnCustomDepth = false, bool bDebounce = true, float DebounceTime = -1.000000f);

	UFUNCTION(BlueprintCallable, Category="Part Modifier|Spawn System", meta=(AdvancedDisplay="11", DefaultToSelf="true", DisplayName="Spawn Emitter Attached Part Modifier (Legacy)", ExpandEnumAsExecs="OutExec", HideSelfPin="true", UnsafeDuringActorConstruction="true", CPP_Default_AttachPointName="None", CPP_Default_Location, CPP_Default_Rotation))
	UParticleSystemComponent* SpawnEmitterAttachedPartModifier(ECosmeticModifierOutExec& OutExec, UParticleSystem* EmitterTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale = FVector(1.000000, 1.000000, 1.000000), EAttachLocation::Type LocationType = EAttachLocation::KeepRelativeOffset, bool bAutoDestroy = true, EPSCPoolMethod PoolingMethod = EPSCPoolMethod::None, bool bAutoActivate = true, bool bMatchPawnCustomDepth = true, bool bDebounce = true, float DebounceTime = -1.000000f);

	UFUNCTION(BlueprintCallable, Category="Part Modifier|Spawn System", meta=(AdvancedDisplay="11", DefaultToSelf="true", ExpandEnumAsExecs="OutExec", HideSelfPin="true", Keywords="spawn system attached niagara", UnsafeDuringActorConstruction="true", CPP_Default_Rotation))
	UNiagaraComponent* SpawnSystemAtLocationPartModifier(ECosmeticModifierOutExec& OutExec, UNiagaraSystem* SystemTemplate, FVector Location, FRotator Rotation, FVector Scale = FVector(1.000000, 1.000000, 1.000000), bool bAutoDestroy = true, bool bAutoActivate = true, bool bOwnedByModifier = false, ENCPoolMethod PoolingMethod = ENCPoolMethod::None, bool bPreCullCheck = true, bool bMatchPawnCustomDepth = false, bool bDebounce = false, float DebounceTime = -1.000000f);

	UFUNCTION(BlueprintCallable, Category="Part Modifier|Spawn System", meta=(AdvancedDisplay="12", DefaultToSelf="true", ExpandEnumAsExecs="OutExec", HideSelfPin="true", Keywords="Spawn System Attached", UnsafeDuringActorConstruction="true"))
	UNiagaraComponent* SpawnSystemAttachedPartModifier(ECosmeticModifierOutExec& OutExec, UNiagaraSystem* SystemTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, EAttachLocation::Type LocationType, bool bAutoDestroy = true, bool bAutoActivate = true, bool bOwnedByModifier = true, ENCPoolMethod PoolingMethod = ENCPoolMethod::None, bool bPreCullCheck = true, bool bMatchPawnCustomDepth = true, bool bDebounce = false, float DebounceTime = -1.000000f);

protected:
	UFUNCTION()
	virtual void NativePawnCustomizationFinished(AFortPlayerPawn* PlayerPawn);

	UFUNCTION()
	void NativeWeaponFired(AFortWeapon* FiringWeapon);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void PreDestruction();

	UPROPERTY(EditAnywhere, Category="Callbacks", meta=(Categories="CurieState"))
	FGameplayTagContainer CurieElementsToCareAbout;

	UPROPERTY(EditAnywhere, Category="Callbacks")
	EVehicleEnteredCosmeticReaction EnteredVehicleSeatsToCareAbout;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerPawn> FortPlayerPawnPtr;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UPrimitiveComponent>> SpawnedComponents;

	UPROPERTY()
	uint8 bUsesCharacterCustomizationFinished : 1;

	UPROPERTY()
	uint8 bUsesDayPhaseChange : 1;

	UPROPERTY()
	uint8 bUsesWeaponChangeDelegate : 1;

	UPROPERTY()
	uint8 bUsesWeaponFire : 1;

	UPROPERTY()
	uint8 bUsesNewWeapon : 1;

	UPROPERTY()
	uint8 bUsesWeaponChange : 1;

	UPROPERTY()
	uint8 bUsesCurieWhatsoever : 1;

	UPROPERTY()
	uint8 bUsesCurieAttach : 1;

	UPROPERTY()
	uint8 bUsesCurieDetach : 1;

	UPROPERTY()
	uint8 bUsesEnteredVehicle : 1;

	UPROPERTY()
	uint8 bUsesExitVehicle : 1;

	UPROPERTY()
	uint8 bUsesTargetingOrFirstPersonCameraChange : 1;

	UPROPERTY()
	uint8 bUsesOnHitPawn : 1;

	UPROPERTY()
	uint8 bUsesOnBeginSkydiving : 1;

	UPROPERTY()
	uint8 bUsesOnEndSkydiving : 1;

	UPROPERTY()
	uint8 bUsesPawnJumped : 1;

	UPROPERTY()
	uint8 bUsesPawnLanded : 1;

	UPROPERTY()
	uint8 bUsesBeginSwimming : 1;

	UPROPERTY()
	uint8 bUsesEndSwimming : 1;

	UPROPERTY()
	uint8 bUsesBeginSliding : 1;

	UPROPERTY()
	uint8 bUsesEndSliding : 1;

private:
	UFUNCTION()
	void HandleMovementModeChanged(const ACharacter* Character, const EMovementMode PrevMovementMode, const uint8 PreviousCustomMode);

	UFUNCTION()
	void HandlePawnJumped();

	UFUNCTION()
	void HandlePawnLanded(const FHitResult& Hit);

	UFUNCTION()
	void HandleSetFirstPersonCameraOrPawnTargetingChanged(bool bChanged);

	UFUNCTION()
	void NativeEnteredVehicle();

	UFUNCTION()
	void NativeExitedVehicle();

	UFUNCTION()
	void NativeOnHitPawn(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void OnNativeCurieAttached(UObject* CurieOwner, FCurieContainerHandle ContainerHandle, const FGameplayTag& Tag);

	UFUNCTION()
	void OnNativeCurieDetached(UObject* CurieOwner, FCurieContainerHandle ContainerHandle, const FGameplayTag& Tag);

	UFUNCTION()
	void OnPlayerWeaponChanged(AFortWeapon* NewWeapon, AFortWeapon* OldWeapon);

	UPROPERTY(Transient)
	uint8 bRegisteredForDayPhaseChange : 1;

	UPROPERTY(Transient)
	uint8 bRegisteredForSkydiving : 1;

	UPROPERTY(Transient)
	uint8 bRegisteredForTargetingOrFirstPersonCamera : 1;

	UPROPERTY(Transient)
	uint8 bRegisteredForWeaponChanges : 1;

	UPROPERTY(Transient)
	uint8 bRegisteredForCurieChanges : 1;

	UPROPERTY(Transient)
	uint8 bRegisteredForNewWeapons : 1;

	UPROPERTY(Transient)
	uint8 bRegisteredForEnterVehicle : 1;

	UPROPERTY(Transient)
	uint8 bRegisteredForExitVehicle : 1;

	UPROPERTY(Transient)
	uint8 bRegisteredOnHitPawn : 1;

	UPROPERTY(Transient)
	uint8 bInVehicle : 1;

};

