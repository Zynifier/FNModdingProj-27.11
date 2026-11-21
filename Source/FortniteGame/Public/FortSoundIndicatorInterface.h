// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTeamEnum.h"
#include "FortSoundIndicatorInterface.generated.h"

class AFortPlayerController;

UINTERFACE(MinimalAPI, BlueprintType)
class UFortSoundIndicatorInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortSoundIndicatorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Sound Indicator Interface")
	TArray<TEnumAsByte<EFortTeamAffiliation::Type>> GetAffiliationsToShowFor() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Sound Indicator Interface")
	bool ShouldShowSoundIndicator(AFortPlayerController* PlayerController) const;

};

