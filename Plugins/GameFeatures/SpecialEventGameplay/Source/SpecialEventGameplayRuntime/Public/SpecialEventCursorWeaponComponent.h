// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Components/FortWeaponComponent.h"
#include "SpecialEventCursorPawnComponent.h"
#include "SpecialEventCursorWeaponComponent.generated.h"

class AFortPlayerPawn;
class AFortWeapon;
class UFXSystemComponent;
class USpecialEventCursorPawnComponent;
class USpecialEventCursorWeaponComponent;
enum class EFortAbilityTargetingSource : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSpecialEventCursorWeaponComponent_OnCursorPawnComponentSet, USpecialEventCursorPawnComponent*, CursorPawnComponent, AFortWeapon*, Weapon);

UCLASS(BlueprintType, HideCategories=("Collision", "ComponentReplication", "ComponentTick", "Cooking", "Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class USpecialEventCursorWeaponComponent : public UFortWeaponComponent, public ISpecialEventCursorInstigatorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintCosmetic, meta=(ExpandBoolAsExecs="ReturnValue"))
	bool GetCurrentHitResult(FHitResult& OutHitResult) const;

	UFUNCTION(BlueprintCallable)
	static USpecialEventCursorWeaponComponent* GetCurrentSpecialEventCursorWeaponComponent(const AFortPlayerPawn* Pawn);

	UFUNCTION(BlueprintPure)
	USpecialEventCursorPawnComponent* GetCursorPawnComponent() const;

	UFUNCTION(BlueprintCallable)
	static USpecialEventCursorPawnComponent* GetSpecialEventCursorPawnComponentForCurrentWeapon(const AFortPlayerPawn* Pawn);

	UFUNCTION(BlueprintCallable)
	static USpecialEventCursorPawnComponent* GetSpecialEventCursorPawnComponentForWeapon(const AFortWeapon* Weapon);

	UPROPERTY(BlueprintAssignable)
	FSpecialEventCursorWeaponComponent_OnCursorPawnComponentSet OnCursorPawnComponentSet;

protected:
	UFUNCTION()
	void OnRep_CursorPawnComponent();

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorWeaponComponent")
	TSubclassOf<USpecialEventCursorPawnComponent> CursorPawnComponentClass;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorWeaponComponent")
	FGameplayTag CursorModeTag;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorWeaponComponent")
	bool bAlignFXToCursor;

private:
	UFUNCTION()
	void OnBeamFired(AFortWeapon* Weapon, bool bUsePersistentBeam, UFXSystemComponent* PSC, const FVector& BeamOrigin, const FVector& HitLocation);

	UFUNCTION()
	void OnEquip(AFortWeapon* Weapon);

	UFUNCTION()
	void OnGetAimRotOverride(const AFortWeapon* Weapon, const EFortAbilityTargetingSource TargetingSource, FRotator& OutOverride, bool& bOutExecutionResult);

	UFUNCTION()
	void OnPlayImpactFX(AFortWeapon* Weapon, const FHitResult& HitResult, UFXSystemComponent* FXSystemComponent);

	UFUNCTION()
	void OnUnEquip(AFortWeapon* Weapon);

	UPROPERTY()
	TObjectPtr<AFortWeapon> OwningWeapon;

	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> Pawn;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CursorPawnComponent, Export, meta=(EditInline="true"))
	TObjectPtr<USpecialEventCursorPawnComponent> CursorPawnComponent;

};

