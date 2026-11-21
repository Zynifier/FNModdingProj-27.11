// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortExhibitActor.h"
#include "FortHeroExhibitActor.generated.h"

class AFortPlayerPawn;
class UFortHeroType;

UCLASS()
class AFortHeroExhibitActor : public AFortExhibitActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Exhibit")
	TObjectPtr<UFortHeroType> HeroType;

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawn> HeroExhibitPawn;

};

