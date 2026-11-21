// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/FortDecoPreview.h"
#include "FortTrackPreview.generated.h"

class UStaticMesh;
class UStaticMeshComponent;

UCLASS(BlueprintType, Blueprintable)
class AFortTrackPreview : public AFortDecoPreview
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Track")
	void InitializeTrackPreview(UStaticMeshComponent* InTrackMeshComp);

	UPROPERTY(EditDefaultsOnly, Category="Track", meta=(ArraySizeEnum="/Script/FortniteGame.ETrackPieceType"))
	TObjectPtr<UStaticMesh> TrackPieceMeshesByType[5];

	UPROPERTY(EditDefaultsOnly, Category="Track")
	float CellSize;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> TrackMeshComp;

};

