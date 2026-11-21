// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "FortHookGunRope.generated.h"

class AFortProjectileBase;
class AFortWeapon;
class USkeletalMeshComponentBudgeted;
class UStaticMeshComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndReel);

USTRUCT(BlueprintType)
struct FHookGunRopeRepData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="HookGun")
	TWeakObjectPtr<AFortWeapon> Weapon;

	UPROPERTY(BlueprintReadWrite, Category="HookGun")
	TWeakObjectPtr<AFortProjectileBase> Projectile;

};

UCLASS(BlueprintType, Blueprintable)
class AFortHookGunRope : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_HookGunRopeRepData();

	UFUNCTION(BlueprintCallable)
	void SetOwningProjectileMesh(UStaticMeshComponent* NewValue);

	UFUNCTION(BlueprintCallable)
	void SetStartPointOfRope();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetWeaponAndProjectile(AFortWeapon* InWeapon, AFortProjectileBase* InProjectile);

	UFUNCTION(BlueprintCallable)
	void SetWeaponMesh(USkeletalMeshComponentBudgeted* NewValue);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Static Mesh", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> RopeMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Static Mesh", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> RopeProjectileMesh;

	UPROPERTY(BlueprintReadOnly, Category="FortHookGunRope")
	FVector StartLocation;

	UPROPERTY(BlueprintReadOnly, Category="FortHookGunRope")
	FVector EndLocation;

	UPROPERTY(BlueprintReadOnly, Export, Category="Weapon", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponentBudgeted> WeaponMesh;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	FName WeaponMeshSocketName;

	UPROPERTY(BlueprintReadOnly, Export, Category="Static Mesh", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> OwningProjectileMesh;

	UPROPERTY(EditDefaultsOnly, Category="Static Mesh")
	FName OwningProjectileMeshSocketName;

	UPROPERTY(BlueprintAssignable)
	FOnEndReel OnEndReel;

	UPROPERTY(BlueprintReadWrite, Category="Projectile")
	bool bProjectileGone;

	UPROPERTY(ReplicatedUsing=OnRep_HookGunRopeRepData)
	FHookGunRopeRepData HookGunRopeRepData;

};

