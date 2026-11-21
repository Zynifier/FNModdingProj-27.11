// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Athena/AI/FortAthenaPatrolPath.h"
#include "FortNavPathRendererComponent.generated.h"

class IFortNavPathRendererInfoInterface;
class UNiagaraComponent;
class UNiagaraSystem;

UENUM()
enum class ENavPathRendererStatus : uint8
{
	INVALID = 0,
	CALCULATING = 1,
	SUCCESS = 2,
	FAILED = 3,
};

USTRUCT()
struct FPathRendererDetails
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FVector> PathPoints;

	UPROPERTY(Transient)
	ENavPathRendererStatus PathStatus;

};

USTRUCT()
struct FPathRendererInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TScriptInterface<IFortNavPathRendererInfoInterface> PathRendererInterface;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortNavPathRendererComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void DeactivateFX();

	UFUNCTION(BlueprintCallable)
	void UpdatePathsVisualOnClient();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FX")
	TObjectPtr<UNiagaraSystem> PathVFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FX")
	FVector PathVFXOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FX")
	TArray<FColor> PathColors;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> PathVFXComponent;

	UPROPERTY(Transient)
	TArray<FPathRendererInfo> PathRendererList;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PathPointsUpdated)
	TArray<FVector4f> AllPathsPoints;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortNavPathRendererComponent")
	TArray<FVector> NavPathPoints;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortNavPathRendererComponent")
	TArray<int32> NavPathPointsStatus;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PathModeUpdated)
	EPatrollingMode PathMode;

private:
	UFUNCTION()
	void OnRep_ColorIndexUpdated();

	UFUNCTION()
	void OnRep_PathModeUpdated();

	UFUNCTION()
	void OnRep_PathPointsUpdated();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ColorIndexUpdated)
	int32 CurrentPathColorIndex;

};

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortNavPathRendererInfoInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEAI_API IFortNavPathRendererInfoInterface
{
	GENERATED_BODY()

};

