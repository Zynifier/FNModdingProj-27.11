// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateColor.h"
#include "Capture/FortCarriedObjectHolderInterface.h"
#include "Capture/FortCarriedObjectInterface.h"
#include "FortInteractInterface.h"
#include "FortTeamActorInterface.h"
#include "FortCarriedObject.generated.h"

class AActor;
class ABuildingFlagSpawn;
class UProjectileMovementComponent;

UCLASS(Abstract, BlueprintType)
class AFortCarriedObject : public AActor, public IFortCarriedObjectInterface, public IFortTeamActorInterface, public IFortInteractInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Spawn")
	virtual AActor* GetHoldingActor() const;

	UFUNCTION(BlueprintCallable, Category="Spawn")
	void ReturnToSpawnPoint();

protected:
	UFUNCTION()
	virtual void OnRep_HolderInfo(FCarriedObjectAttachmentInfo& PreviousInfo);

	UPROPERTY(ReplicatedUsing=OnRep_HolderInfo)
	FCarriedObjectAttachmentInfo HolderInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HUD")
	FVector IndicatorRelativeOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HUD")
	FSlateBrush Indicator;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HUD")
	FSlateColor DefaultIndicatorColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Offset")
	FVector RelativeTranslation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Offset")
	FRotator RelativeRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	bool bPickupOnTouch;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, Category="FortCarriedObject")
	uint8 Team;

	UPROPERTY(Replicated)
	TObjectPtr<ABuildingFlagSpawn> SpawnPointActor;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UProjectileMovementComponent> ProjectileComp;

};

