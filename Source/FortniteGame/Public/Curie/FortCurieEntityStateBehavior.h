// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Curie/Elements/Handlers/FortCurieElementDamageSourceInterface.h"
#include "CurieEntityStateBehavior.h"
#include "FortCurieEntityStateBehavior.generated.h"

UCLASS(Abstract, MinimalAPI)
class UFortCurieEntityStateBehavior : public UCurieEntityStateBehavior, public IFortCurieElementDamageSourceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Balance")
	uint8 bActAsDmgSrcDirectly : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieEntityStateBehavior")
	uint8 bLightweightState : 1;

	UPROPERTY(EditDefaultsOnly, Category="Balance", meta=(EditCondition="bActAsDmgSrcDirectly"))
	FDataTableRowHandle DamageDataTableRowHandle;

};

