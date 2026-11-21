// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameFramework/Actor.h"
#include "FortHotfixBehaviorVolume.generated.h"

class AActor;
class UBoxComponent;
class UPrimitiveComponent;

UCLASS()
class AFortHotfixBehaviorVolume : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(meta=(CallInEditor="true"))
	void CopyToClipboard();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditInstanceOnly, Export, Category="FortHotfixBehaviorVolume", meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> TriggerBoxComponent;

};

