// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "LatencyGraph.generated.h"

UCLASS(meta=(DisableNativeTick))
class ULatencyGraph : public UUserWidget
{
	GENERATED_BODY()

public:
	ULatencyGraph(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, Category="Display")
	FColor TotalLatencyLineColor;

	UPROPERTY(EditAnywhere, Category="Display")
	FColor GameLatencyLineColor;

	UPROPERTY(EditAnywhere, Category="Display")
	FColor RenderLatencyLineColor;

	UPROPERTY(EditAnywhere, Category="Display")
	FColor DriverLatencyLineColor;

	UPROPERTY(EditAnywhere, Category="Display")
	FColor OSWorkQueueLatencyLineColor;

	UPROPERTY(EditAnywhere, Category="Display")
	FColor GPURenderLatencyLineColor;

	UPROPERTY(EditAnywhere, Category="Display")
	FColor BackgroundColor;

	UPROPERTY(EditAnywhere, Category="Display")
	float MaxLatencyToGraph;

	UPROPERTY(EditAnywhere, Category="Display")
	FVector2D DesiredSize;

};

