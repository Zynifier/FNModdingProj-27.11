// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "FortMarkActor.generated.h"

class AActor;
class AFortPlayerStateZone;

UCLASS(HideCategories=("Collision"))
class AFortMarkActor : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_AttachedToActor();

	UPROPERTY(Replicated)
	TWeakObjectPtr<AFortPlayerStateZone> OwningPlayer;

	UPROPERTY(Replicated)
	FString MarkString;

	UPROPERTY(Replicated)
	FText PreapprovedMarkString;

	UPROPERTY(Replicated)
	bool bFinishedEditing;

	UPROPERTY(ReplicatedUsing=OnRep_AttachedToActor)
	TObjectPtr<AActor> AttachedToActor;

	UPROPERTY(Replicated)
	FVector AttachmentOffset;

	UPROPERTY()
	FSlateBrush MiniMapIconBrush;

};

