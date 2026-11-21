// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/Markers/FortMarkableActorInterface.h"
#include "Athena/Markers/MarkedActorDisplayInfo.h"
#include "Building/BuildingSMActor.h"
#include "FortHeistDisplayCase.generated.h"

class AFortPlayerPawn;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingSMActorClassData)
class AFortHeistDisplayCase : public ABuildingSMActor, public IFortMarkableActorInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Interaction")
	void OnServerNotifyEndDisplayCaseLongUse(AFortPlayerPawn* InteractingPawn, bool bUseCompleted);

	UFUNCTION(BlueprintImplementableEvent, Category="Interaction")
	void OnServerNotifyStartDisplayCaseLongUse(AFortPlayerPawn* InteractingPawn);

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	bool bReplicateLongInteractionDetails;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Marking")
	uint8 bCanBeMarked : 1;

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	uint8 bBlockMarking : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Marking")
	FMarkedActorDisplayInfo MarkerDisplay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Marking")
	FVector MarkerPositionOffset;

};

