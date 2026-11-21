// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Building/BuildingActor.h"
#include "FortMatchmakingActor.generated.h"

class UUserWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingActorClassData)
class AFortMatchmakingActor : public ABuildingActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	FString GetMMSCodeForLocalPlayerParty();

	UFUNCTION(BlueprintPure)
	bool ShouldUseBlueprintMMSCode() const;

	UPROPERTY(EditDefaultsOnly, Category="FortMatchmakingActor")
	FText LeaderInteractDetailsText;

	UPROPERTY(EditDefaultsOnly, Category="FortMatchmakingActor")
	FLinearColor LeaderInteractDetailsColor;

	UPROPERTY(EditDefaultsOnly, Category="FortMatchmakingActor")
	FText MemberInteractDetailsText;

	UPROPERTY(EditDefaultsOnly, Category="FortMatchmakingActor")
	FLinearColor MemberInteractDetailsColor;

private:
	UPROPERTY(EditAnywhere, Category="FortMatchmakingActor")
	TSoftClassPtr<UUserWidget> MatchmakingWidgetClass;

};

