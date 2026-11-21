// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PapayaAnalyticsComponent.generated.h"

class UPapayaAnalyticsComponent;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UPapayaAnalyticsComponent : public UFortPlayspaceComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPapayaAnalyticsComponent> ParentAnalyticsComp;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPapayaAnalyticsComponent> ChildAnalyticsComp;

};

