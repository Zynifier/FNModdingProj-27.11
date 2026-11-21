// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/SpecialActor/FortEventLevelNavigationActor.h"
#include "FortNavigationActor_MapTable.generated.h"

class UStaticMeshComponent;

UCLASS(Abstract, Config=Game, DefaultConfig, MinimalAPI)
class AFortNavigationActor_MapTable : public AFortEventLevelNavigationActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnActiveEventsChanged();

protected:
	UFUNCTION()
	void HandleActiveEventsChanged(const TArray<FString>& ActiveEventFlags);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortNavigationActor_MapTable", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> ApolloMap;

	UPROPERTY(VisibleAnywhere, Export, Category="FortNavigationActor_MapTable", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> ReferencePlane;

	UPROPERTY(Config)
	FVector ApolloMapMinLoc;

	UPROPERTY(Config)
	FVector ApolloMapMaxLoc;

	UPROPERTY(Config)
	FVector UnscaledPlaneExtent;

};

