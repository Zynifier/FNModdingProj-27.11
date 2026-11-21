// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SpecialActor/FortEventLevelNavigationActor.h"
#include "FortNavigationActor_DailyChallengeBoard.generated.h"

class UStaticMeshComponent;

UCLASS(Abstract, MinimalAPI)
class AFortNavigationActor_DailyChallengeBoard : public AFortEventLevelNavigationActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortNavigationActor_DailyChallengeBoard", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UStaticMeshComponent> S_NoteCard_Top;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortNavigationActor_DailyChallengeBoard", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UStaticMeshComponent> S_NoteCard_Middle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortNavigationActor_DailyChallengeBoard", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UStaticMeshComponent> S_NoteCard_Bottom;

};

