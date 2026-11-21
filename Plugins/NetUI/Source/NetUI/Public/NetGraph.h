// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "NetGraph.generated.h"

UCLASS(meta=(DisableNativeTick))
class UNetGraph : public UUserWidget
{
	GENERATED_BODY()

public:
	UNetGraph(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, Category="Display")
	FColor BackgroundColor;

	UPROPERTY(EditAnywhere, Category="Display")
	FColor PingLineColor;

	UPROPERTY(EditAnywhere, Category="Display")
	FColor QueuedBunchesLineColor;

	UPROPERTY(EditAnywhere, Category="Display")
	FColor PacketLossLineColor;

	UPROPERTY(EditAnywhere, Category="Display")
	FVector2D DesiredSize;

	UPROPERTY(EditAnywhere, Category="Display")
	float MaxPingToGraph;

};

