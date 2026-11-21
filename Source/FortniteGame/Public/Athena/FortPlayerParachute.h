// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraFramingTypes.h"
#include "Cosmetics/FortAthenaLoadoutProvider.h"
#include "FrontEnd/CosmeticPreviewInterface.h"
#include "FortPlayerParachute.generated.h"

class AFortPlayerPawn;
class UAthenaGliderItemDefinition;
class UAudioComponent;
class UFXSystemComponent;
class UFortGliderAudioComponent;
class UFortPlayerGliderAnimSet;
class UNiagaraComponent;
class UObject;
class UParticleSystemComponent;
class USkeletalMeshComponent;
class USkeletalMeshComponentBudgeted;
class USoundBase;
enum class EFortDayPhase : uint8;

UCLASS(BlueprintType, Blueprintable)
class AFortPlayerParachute : public AActor, public IFortUICameraFrameTargetInterface, public ICosmeticPreviewInterface, public IFortAthenaLoadoutProvider
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ApplyVariants();

	UFUNCTION(BlueprintCallable)
	void DisableTrailParticles();

	UFUNCTION(BlueprintPure)
	TArray<USkeletalMeshComponentBudgeted*> GetBitsMeshComponents() const;

	UFUNCTION(BlueprintPure)
	AFortPlayerPawn* GetFortPlayerPawn() const;

	UFUNCTION(BlueprintPure)
	USkeletalMeshComponent* GetParachuteRootMesh() const;

	UFUNCTION(BlueprintPure)
	UFXSystemComponent* GetTrailVFX2Component() const;

	UFUNCTION(BlueprintPure)
	UFXSystemComponent* GetTrailVFXComponent() const;

	UFUNCTION(BlueprintCallable)
	void InitalizeFromItemDef(const UAthenaGliderItemDefinition* InParachuteItemDef, bool bSynchronousLoad);

	UFUNCTION(BlueprintPure)
	bool IsGliderFullyDeployedAccordingToAnim() const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Chute Visibility Changed"))
	void K2_SetChuteMeshVisibility(bool bParachuteVisibility);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnDayPhaseChanged(EFortDayPhase CurrentDayPhase, EFortDayPhase PreviousDayPhase, bool bAtCreation);

	UFUNCTION(BlueprintImplementableEvent)
	void OnGliderFullyDeployed();

	UFUNCTION(BlueprintCallable)
	void SetChuteMeshVisibility(bool bNewParachuteVisible);

	UFUNCTION(BlueprintCallable)
	void SetPlayerPawn(AFortPlayerPawn* InPlayerPawn);

	UPROPERTY(Transient)
	TSoftObjectPtr<USoundBase> GliderOpenSoundFromDef;

	UPROPERTY(Transient)
	TSoftObjectPtr<USoundBase> GliderOpenFrontEndSoundFromDef;

	UPROPERTY(Transient)
	TObjectPtr<USoundBase> CurrentGliderOpenSound;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UAudioComponent> CurrentGliderOpenAudioComponent;

	UPROPERTY(Transient)
	TSoftObjectPtr<USoundBase> GliderCloseSoundFromDef;

	UPROPERTY(Transient)
	TObjectPtr<USoundBase> CurrentGliderCloseSound;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UAudioComponent> CurrentGliderCloseAudioComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Parachute", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortGliderAudioComponent> FortLayeredAudioComponentGlider;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="FortPlayerParachute")
	bool IsCosmeticPreview;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerParachute")
	uint8 bIsEtherealBackgroundPreview : 1;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> TrailVFX;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> TrailVFX2;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortPlayerParachute", meta=(EditInline="true"))
	TArray<TObjectPtr<UNiagaraComponent>> TrailComponents;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gameplay")
	uint8 bUsesDayPhaseChange : 1;

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Parachute")
	void OnParachuteTrailUpdated(float MovementLengthSquared, float ForwardDot, float RightDot, float RotationalMovementAcceleration);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Parachute")
	void OnPlayerPawnSet();

	UFUNCTION(BlueprintImplementableEvent, Category="Parachute")
	void OnReceiveParachuteItemdef();

	UFUNCTION()
	void OnRep_ParachuteItemDef();

	UFUNCTION()
	void OnRep_PlayerPawn(const AFortPlayerPawn* PreviousPlayerPawn);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_PlayerPawn, Category="FortPlayerParachute")
	TObjectPtr<AFortPlayerPawn> PlayerPawn;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ParachuteItemDef, Category="FortPlayerParachute")
	TObjectPtr<UAthenaGliderItemDefinition> ParachuteItemDef;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parachute")
	float ParachuteHiddenAnimFinishTime;

	UPROPERTY()
	uint8 bGliderFullyLoaded : 1;

	UPROPERTY()
	uint8 bGliderFullyDeployed : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerParachute")
	uint8 bChuteOpened : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerParachute")
	uint8 bIsFrontEndPreview : 1;

	UPROPERTY(Transient)
	uint8 bParachuteVisible : 1;

	UPROPERTY(Transient)
	uint8 bCustomizedPreview : 1;

	UPROPERTY(Transient)
	uint8 bActivateTrailOnRotationalMovement : 1;

	UPROPERTY(Transient)
	FRotator LastRotationalMovement;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parachute")
	FName ParachuteTrailParameterName;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Parachute", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USkeletalMeshComponentBudgeted> ParachuteMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Parachute", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UParticleSystemComponent> TrailParticles;

	UPROPERTY(Transient)
	TObjectPtr<UFortPlayerGliderAnimSet> CurrentGliderPlayerAnimSet;

	UPROPERTY(VisibleAnywhere, Transient, Export, Category="Parachute", meta=(EditInline="true"))
	TArray<TObjectPtr<USkeletalMeshComponentBudgeted>> BitsMeshComponents;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UObject>> LoadedAssets;

	UPROPERTY(Transient)
	TMap<TObjectPtr<UNiagaraComponent>, int32> TrailComponentDefinitionMap;

};

