// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "FortHotfixUndergroundVolume.generated.h"

class AActor;
class UBoxComponent;
class UPrimitiveComponent;

UCLASS()
class AFortHotfixUndergroundVolume : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(meta=(CallInEditor="true"))
	void CopyToClipboard();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void OnRep_ReplicatedExtent();

	UPROPERTY(EditInstanceOnly, Export, Category="FortHotfixUndergroundVolume", meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> TriggerBoxComponent;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedExtent)
	FVector ReplicatedExtent;

	UPROPERTY(EditInstanceOnly, Category="FortHotfixUndergroundVolume")
	bool bNeededOnClient;

};

