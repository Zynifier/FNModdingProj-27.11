// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Math/MathFwd.h"
#include "FortClientOnlyActor.h"
#include "FortTracerBase.generated.h"

class UBulletWhipTrackerComponentBase;
class UMovementComp_Tracer;
class UStaticMeshComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Actor", "Navigation", "Replication"))
class AFortTracerBase : public AFortClientOnlyActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Tracer")
	void Init(const FVector& Start, const FVector& End);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	FCurveTableRowHandle Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float SpeedScaleMinRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float SpeedScaleMaxRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float SpeedScaleMinMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float SpeedScaleMaxMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Visual")
	FVector MeshScaleMult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Visual")
	float MeshScaleTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TSubclassOf<UBulletWhipTrackerComponentBase> BulletWhipTrackerComponentClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Visual")
	uint8 bScaleOnDeath : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	uint8 bScaleSpeed : 1;

	UPROPERTY(VisibleInstanceOnly, Transient, Category="Debug")
	uint8 bScaledUp : 1;

	UPROPERTY(VisibleInstanceOnly, Transient, Category="Debug")
	uint8 bDead : 1;

	UPROPERTY(VisibleInstanceOnly, Transient, Category="Debug")
	uint8 bOwnedByPool : 1;

	UPROPERTY(VisibleInstanceOnly, Transient, Category="Debug")
	float CurrentScale;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Movement", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UMovementComp_Tracer> TracerMovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Visual", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> TracerMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Visual", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UBulletWhipTrackerComponentBase> BulletWhipTrackerComponent;

};

