// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "FortHotfixBlockingVolume.generated.h"

class UBoxComponent;

UCLASS()
class AFortHotfixBlockingVolume : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(meta=(CallInEditor="true"))
	void CopyToClipboard();

	UFUNCTION()
	void OnRep_ReplicatedExtent();

	UPROPERTY(EditInstanceOnly, Export, Category="FortHotfixBlockingVolume", meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> BlockBoxComponent;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedExtent)
	FVector ReplicatedExtent;

	UPROPERTY(EditInstanceOnly, Category="FortHotfixBlockingVolume")
	bool bNeededOnClient;

};

