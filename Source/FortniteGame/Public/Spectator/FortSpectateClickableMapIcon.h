// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Styling/SlateBrush.h"
#include "FortSpectateClickableMapIcon.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortSpectateClickableMapIcon : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Map")
	FSlateBrush SpectatorMapIndicatorBrush;

};

