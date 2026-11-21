// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/HitResult.h"
#include "FortAutoMarkableActorComponent.generated.h"

class AActor;
class AFortPlayerController;
class UPrimitiveComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAutoMarkableActorComponentMarked, AActor*, MarkedActor, AFortPlayerController*, PlayerController);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAutoMarkableActorComponentUnmarked, AActor*, UnmarkedActor, AFortPlayerController*, PlayerController);

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UFortAutoMarkableActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetAutoMarkCollisionComponent(UPrimitiveComponent* InAutoMarkCollisionComponent);

	UPROPERTY(EditDefaultsOnly, Category="FortAutoMarkableActorComponent")
	bool bUseHoveredMarkerDetail;

	UPROPERTY(BlueprintAssignable)
	FOnAutoMarkableActorComponentMarked OnAutoMarkableActorComponentMarked;

	UPROPERTY(BlueprintAssignable)
	FOnAutoMarkableActorComponentUnmarked OnAutoMarkableActorComponentUnmarked;

protected:
	UFUNCTION()
	virtual void OnAutoMarkCollisionChanged(UPrimitiveComponent* ChangedComponent);

	UFUNCTION()
	virtual void OnAutoMarkCollisionComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnAutoMarkCollisionComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};

