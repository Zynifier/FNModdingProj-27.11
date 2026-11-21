// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavGraphDebugActor.generated.h"

class UBillboardComponent;

UCLASS()
class ANavGraphDebugActor : public AActor
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Transient, Category="Graph")
	int32 CellX;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Transient, Category="Graph")
	int32 CellY;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Transient, Category="Graph")
	int32 CellZ;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Transient, Category="Graph")
	int32 NodeId;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

};

