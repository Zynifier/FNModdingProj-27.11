// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Showdown/FortShowdownDetailView.h"
#include "FortShowdownPin.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortShowdownPin : public UFortShowdownDetailView
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetAlternativeScoreToDisplay() const;

	UFUNCTION(BlueprintCallable)
	int32 GetScoreToDisplay(bool bUseBestPin);

protected:
	UFUNCTION(BlueprintPure)
	bool ShouldUseAlternativeScore() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortShowdownPin")
	bool bTryUsingAlternativeScore;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortShowdownPin")
	bool bUseAbbreviatedScore;

private:
	UPROPERTY(Transient)
	int32 LastBestScore;

};

